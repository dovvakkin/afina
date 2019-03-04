#include "SimpleLRU.h"
#include <iostream>

namespace Afina {
namespace Backend {

void SimpleLRU::_free_until_fit(size_t needed_size) {
    while(_free_size < needed_size) {
        _lru_index.erase(_lru_head->value);
        _free_size += (_lru_head->value.size() + _lru_head->key.size());
        _lru_head.swap(_lru_head->next);
        _lru_head->prev->next = nullptr;
        _lru_head->prev = nullptr;
    }
}

void SimpleLRU::_move_to_tail(lru_node &exist) {
    if (exist.next == nullptr) {
        return;
    }

    if (exist.prev == nullptr) {
        exist.next->prev = nullptr;
        exist.next.swap(_lru_head);
        _lru_tail->next.swap(exist.next);
        exist.prev = _lru_tail;
        _lru_tail = &exist;
        return;
    }

    {
        std::unique_ptr<lru_node> buf = nullptr;
        //todo
        //ЖОПА
        exist.prev->next.swap(buf);
        exist.next->prev = exist.prev;
        exist.prev->next.swap(exist.next);
        buf.swap(_lru_tail->next);
        exist.next = nullptr;
        exist.prev = _lru_tail;
        _lru_tail = &exist;
        return;
    }
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Put(const std::string &key, const std::string &value) {
    // if key in map
    if (_lru_index.find(std::reference_wrapper<const std::string>(key)) != _lru_index.end()) {
        return SimpleLRU::Set(key, value);
    } else {
        return SimpleLRU::PutIfAbsent(key, value);
    }
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::PutIfAbsent(const std::string &key, const std::string &value) {
    if ((key.size() + value.size()) > _max_size) {
        return false;
    }

    if (_lru_index.find(std::reference_wrapper<const std::string>(key)) != _lru_index.end()) {
        return false;
    }

    if ((key.size() + value.size()) > _free_size) {
        _free_until_fit(key.size() + value.size());
    }


    _free_size -= (key.size() + value.size());
    auto *added = new lru_node;
    added->key = key;
    added->value = value;
    added->next = nullptr;
    added->prev = nullptr;

    _lru_index.insert({std::reference_wrapper<const std::string>(added->key), std::reference_wrapper<lru_node>
            (*added)});

    if(_lru_tail != nullptr) {
        _lru_tail->next = std::unique_ptr<lru_node>(added);
        _lru_tail->next->prev = _lru_tail;
        _lru_tail = added;
    } else {
        _lru_tail = added;
        _lru_head.reset(added);
    }


    return true;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Set(const std::string &key, const std::string &value) {
    if ((key.size() + value.size()) > _max_size) {
        return false;
    }

    auto fnd = _lru_index.find(std::reference_wrapper<const std::string>(key));
    if (fnd == _lru_index.end()) {
        return false;
    }

    /* code here */
    _move_to_tail(fnd->second.get());

    _free_size += fnd->second.get().value.size();
    _free_until_fit(value.size());

    fnd->second.get().value = value;
    _free_size -= value.size();

    return true;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Delete(const std::string &key) {
    auto fnd = _lru_index.find(std::reference_wrapper<const std::string>(key));
    if (fnd == _lru_index.end()) {
        return false;
    }

    lru_node& exist = fnd->second.get();
    _lru_index.erase(key);
    _free_size += (exist.value.size() + exist.key.size());

    exist.next->prev = exist.prev;
    exist.prev->next.swap(exist.next);
    exist.next = nullptr;

    return true;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Get(const std::string &key, std::string &value) {
    auto fnd = _lru_index.find(std::reference_wrapper<const std::string>(key));
    if (fnd == _lru_index.end()) {
        return false;
    }

    _move_to_tail(fnd->second.get());
    value = fnd->second.get().value;

    return true;
}

} // namespace Backend
} // namespace Afina
