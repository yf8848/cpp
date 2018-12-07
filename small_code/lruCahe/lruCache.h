#include <iostream>
#include <memory>
#include <mutex>
#include <utility>
#include <unordered_map>
#include <string>
#include <list>



class LRUCache
{
public:
    LRUCache();
    LRUCache(uint64_t size);
    ~LRUCache();

    using Item = std::pair<std::string, std::string>;
    using Iter = std::list<Item>::iterator;
    using LRUCacheListPtr = std::shared_ptr<std::list<Item>>;
    using LRUCacheMapPtr  = std::shared_ptr<std::unordered_map<std::string, Iter>>;

public:
    std::string get(const std::string& key);
    void set(const std::string& key, const std::string& value);
    void foreach();

private:
    /* data */
    LRUCacheListPtr lruCache;
    LRUCacheMapPtr lruHashMap;

    uint64_t lruCacheCurSize;
    uint64_t lruCacheMaxSize;
};

