#ifndef AFINA_STORAGE_SIMPLE_LRU_H
#define AFINA_STORAGE_SIMPLE_LRU_H

#include <map>
#include <memory>
#include <mutex>
#include <string>

#include <afina/Storage.h>

namespace Afina {
namespace Backend {

/**
 * # Map based implementation
 * That is NOT thread safe implementaiton!!
 */
class SimpleLRU : public Afina::Storage {
private:
    // LRU cache node
    using lru_node = struct lru_node {
        const std::string key;
        std::string value;
        lru_node *prev;
        std::unique_ptr<lru_node> next;
    };

    using index_map_iterator =
        std::map<std::reference_wrapper<const std::string>, std::reference_wrapper<lru_node>>::iterator;

public:
    SimpleLRU(size_t max_size = 1024) : _max_size(max_size), _free_size(max_size) {}

    ~SimpleLRU() {
        _lru_index.clear();
        while (_lru_head != nullptr && _lru_head->next != nullptr) {
            std::unique_ptr<lru_node> tmp = nullptr;
            tmp.swap(_lru_head->next);
            _lru_head.swap(tmp);
            tmp.reset();
        }
        _lru_head.reset();
    }

    // todo
    bool _PutIfAbsent(const std::string &key, const std::string &value);

    // todo
    bool _Set(const std::string &key, const std::string &value, index_map_iterator &it);

    // Implements Afina::Storage interface
    bool Put(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool PutIfAbsent(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Set(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Delete(const std::string &key) override;

    // Implements Afina::Storage interface
    bool Get(const std::string &key, std::string &value) override;

private:
    // Maximum number of bytes could be stored in this cache.
    // i.e all (keys+values) must be less the _max_size
    std::size_t _max_size;

    // current size of free space
    std::size_t _free_size;

    // Main storage of lru_nodes, elements in this list ordered descending by "freshness": in the head
    // element that wasn't used for longest time.
    //
    // List owns all nodes

    std::unique_ptr<lru_node> _lru_head = nullptr;
    lru_node *_lru_tail = nullptr;

    // Index of nodes from list above, allows fast random access to elements by lru_node#key
    std::map<std::reference_wrapper<const std::string>, std::reference_wrapper<lru_node>, std::less<std::string>>
        _lru_index;

    void _free_until_fit(size_t needed_size);

    void _move_to_tail(lru_node &exist);
};

} // namespace Backend
} // namespace Afina

#endif // AFINA_STORAGE_SIMPLE_LRU_H

// todo
