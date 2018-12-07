#include "lruCache.h"

LRUCache:: LRUCache()
{
    lruCache = std::make_shared<std::list<Item>>();
    lruHashMap = std::make_shared<std::unordered_map<std::string, Iter>>();

    lruCacheCurSize = 0;
    lruCacheMaxSize = 0;
}

LRUCache:: LRUCache(uint64_t size)
{
    lruCache = std::make_shared<std::list<Item>>();
    lruHashMap = std::make_shared<std::unordered_map<std::string, Iter>>();

    lruCacheCurSize = 0;
    lruCacheMaxSize = size;
}

LRUCache::~ LRUCache()
{
}

void LRUCache::set(const std::string& key, const std::string& value)
{
    std::mutex mtx;

    auto itm = std::make_pair(key, value);
    std::lock_guard<std::mutex> lmtx(mtx);
    
    if(lruCacheCurSize<lruCacheMaxSize)
    {
        // 直接插入到最前面
        lruCache->insert(lruCache->begin(), itm);
        lruHashMap->insert({key, lruCache->begin()});
        lruCacheCurSize++;
    }
    else
    {
        lruCache->erase(--lruCache->end());
        lruCache->insert(lruCache->begin(), itm);

        // 判断是否存在
        if(lruHashMap->find(key) != lruHashMap->end())
        {
            //存在更新
            (*lruHashMap)[key] = lruCache->begin();
        }
        else
        {
            //不存在，插入
            lruHashMap->insert({key,lruCache->begin()});
        }
    }
}

std::string LRUCache::get(const std::string& key)
{
    std::mutex mtx;

    std::lock_guard<std::mutex> lmtx(mtx);

    if(lruHashMap->find(key) != lruHashMap->end())
    {
        auto itera = (*lruHashMap)[key];
        auto it = *itera;

        lruCache->erase(itera);
        lruCache->insert(lruCache->begin(), std::move(it));
        (*lruHashMap)[key] = lruCache->begin();

        return (*(*lruHashMap)[key]).second;
    }    
    else
    {
        return "";
    }
}


void LRUCache::foreach()
{
    for(auto& it: *lruCache)
    {
        std::cout<<it.first<< " -> " <<it.second << std::endl;
    }

    std::cout<<std::endl;
}


int main() {
    LRUCache lruCache(5);

    lruCache.set("1", "1");
    lruCache.set("2", "2");
    lruCache.set("3", "3");
    lruCache.set("4", "4");
    lruCache.set("5", "5");

    lruCache.foreach();

    /* 新加节点，大于 size 执行 LRU 策略 */
    lruCache.set("6", "6");
    lruCache.foreach();
    lruCache.set("5", "5");
    lruCache.foreach();

    auto s1 = lruCache.get("5");
    auto s2 = lruCache.get("10");

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

   return 0;
}