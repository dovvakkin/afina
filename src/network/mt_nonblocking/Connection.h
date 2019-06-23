#ifndef AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H
#define AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H

#include <cstring>

#include <afina/execute/Command.h>
#include <protocol/Parser.h>
#include <spdlog/logger.h>
#include <sys/epoll.h>

namespace Afina {
namespace Network {
namespace MTnonblock {

class Connection {
public:
    Connection(int s, std::shared_ptr<Afina::Storage> ps, std::shared_ptr<spdlog::logger> log)
        : _socket(s), pStorage(ps), _logger(log) {
        std::memset(&_event, 0, sizeof(struct epoll_event));
        _event.data.ptr = this;
        _event.events = EPOLLREAD;
        _isAlive.store(true);
    }

    inline bool isAlive() const { return _isAlive; }

    void Start();

protected:
    void OnError();
    void OnClose();
    void DoRead();
    void DoWrite();

private:
    friend class ServerImpl;
    friend class Worker;

    const int EPOLLREAD = EPOLLIN | EPOLLERR | EPOLLRDHUP | EPOLLONESHOT;
    const int EPOLLREADWRITE = EPOLLIN | EPOLLERR | EPOLLRDHUP | EPOLLOUT | EPOLLONESHOT;

    int _socket;
    struct epoll_event _event;
    std::atomic<bool> _isAlive;

//    std::mutex _mutex;
//    std::atomic<bool> _sync_read;
    std::mutex answers_mtx;

    std::shared_ptr<spdlog::logger> _logger;
    std::shared_ptr<Afina::Storage> pStorage;

    size_t arg_remains;
    Protocol::Parser parser;
    std::string argument_for_command;
    std::unique_ptr<Execute::Command> command_to_execute;

    int readed_bytes = 0;
    char client_buffer[4096];

    std::vector<std::string> _answers;
    int _position = 0;
};

} // namespace MTnonblock
} // namespace Network
} // namespace Afina

#endif // AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H
