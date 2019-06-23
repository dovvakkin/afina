#include "Connection.h"



#include <iostream>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

namespace Afina {
namespace Network {
namespace STnonblock {

// See Connection.h
void Connection::Start() {
    _logger->info("Start on descriptor {}", _socket);
    _isAlive = true;
//    _event.data.fd = _socket;
    _event.data.ptr = this;
    _event.events = MASK_EPOLLREAD;
}

// See Connection.h
void Connection::OnError() {
    _logger->info("OnError on descriptor {}", _socket);
    _isAlive = false;
    _logger->error("Error connection on descriptor {}", _socket);
    std::string err_message = "something went wrong\r\n";
    if (send(_socket, err_message.data(), err_message.size(), 0) <= 0) {
        throw std::runtime_error("Failed to send response");
    }
}

// See Connection.h
void Connection::OnClose() {
    _logger->info("OnClose on descriptor {}", _socket);
    _isAlive = false;
//    _logger->debug("Closed connection on descriptor {}", _socket);
//    std::string message = "Connection is closed\r\n";
//    if (send(_socket, message.data(), message.size(), 0) <= 0) {
//        throw std::runtime_error("Failed to send response");
//    }
}

// See Connection.h
void Connection::DoRead() {
    try {
        int readed_bytes_new = -1;
        while ((readed_bytes_new = read(_socket, client_buffer, sizeof(client_buffer))) > 0) {
            readed_bytes += readed_bytes_new;
            _logger->debug("Got {} bytes from socket", readed_bytes);

            // Single block of data readed from the socket could trigger inside actions a multiple times,
            // for example:
            // - read#0: [<command1 start>]
            // - read#1: [<command1 end> <argument> <command2> <argument for command 2> <command3> ... ]
            while (readed_bytes > 0) {
                _logger->debug("Process {} bytes", readed_bytes);
                // There is no command yet
                if (!command_to_execute) {
                    std::size_t parsed = 0;
                    if (parser.Parse(client_buffer, readed_bytes, parsed)) {
                        // There is no command to be launched, continue to parse input stream
                        // Here we are, current chunk finished some command, process it
                        _logger->debug("Found new command: {} in {} bytes", parser.Name(), parsed);
                        command_to_execute = parser.Build(arg_remains);
                        if (arg_remains > 0) {
                            arg_remains += 2;
                        }
                    }

                    // Parsed might fails to consume any bytes from input stream. In real life that could happens,
                    // for example, because we are working with UTF-16 chars and only 1 byte left in stream
                    if (parsed == 0) {
                        break;
                    } else {
                        std::memmove(client_buffer, client_buffer + parsed, readed_bytes - parsed);
                        readed_bytes -= parsed;
                    }
                }

                // There is command, but we still wait for argument to arrive...
                if (command_to_execute && arg_remains > 0) {
                    _logger->debug("Fill argument: {} bytes of {}", readed_bytes, arg_remains);
                    // There is some parsed command, and now we are reading argument
                    std::size_t to_read = std::min(arg_remains, std::size_t(readed_bytes));
                    argument_for_command.append(client_buffer, to_read);

                    std::memmove(client_buffer, client_buffer + to_read, readed_bytes - to_read);
                    arg_remains -= to_read;
                    readed_bytes -= to_read;
                }

                // Thre is command & argument - RUN!
                if (command_to_execute && arg_remains == 0) {
                    _logger->debug("Start command execution");

                    std::string result;
                    command_to_execute->Execute(*pStorage, argument_for_command, result);

                    // Send response
                    result += "\r\n";
                    _answers.push_back(result);

                    // Prepare for the next command
                    command_to_execute.reset();
                    argument_for_command.resize(0);
                    parser.Reset();

                    _event.events = MASK_EPOLLREADWRITE;
                }
            } // while (readed_bytes)
        }

        if (readed_bytes == 0) {
            _logger->debug("Connection closed");
        } else {
            throw std::runtime_error(std::string(strerror(errno)));
        }
    } catch (std::runtime_error &ex) {
        _logger->error("Failed to process connection on descriptor {}: {}", _socket, ex.what());
    }

    // We are done with this connection

    // Prepare for the next command: just in case if connection was closed in the middle of executing something
    command_to_execute.reset();
    argument_for_command.resize(0);
    parser.Reset();

    _event.events = MASK_EPOLLREADWRITE;
}

// See Connection.h
void Connection::DoWrite() {
    struct iovec iovecs[_answers.size()];
    int i = 0;
    for (auto iter : _answers) {
        iovecs[i].iov_len = iter.size();
        iovecs[i].iov_base = &(iter[0]);
        ++i;
    }
    iovecs[0].iov_base = static_cast<char*>(iovecs[0].iov_base) + _position;

    assert(iovecs[0].iov_len > _position);
    iovecs[0].iov_len -= _position;

    int written;
    if ((written = writev(_socket, iovecs, _answers.size())) <= 0) {
        _logger->error("Failed to send response");
    }
    _position += written;

    i = 0;
    for (; i < _answers.size() && (_position >= iovecs[i].iov_len); i++) {
        _position -= iovecs[i].iov_len;
    }

    _answers.erase(_answers.begin(), _answers.begin() + i);
    if (_answers.empty()) {
        _event.events = MASK_EPOLLREAD;
    }
}

} // namespace STnonblock
} // namespace Network
} // namespace Afina
