#include "lc.h"

class LRUCache {
    typedef list<pair<int, int>> CacheList;
    typedef CacheList::iterator CacheIterator;
    typedef unordered_map<int, CacheIterator> CacheHashMap;
    CacheList _cache_list;
    CacheHashMap _cache_map;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        int ret = -1;
        auto iter = _cache_map.find(key);
        if (iter != _cache_map.end())
        {
            ret = iter->second->second;
            _cache_list.erase(iter->second);
            _cache_list.emplace_front(key, ret);
            iter->second = _cache_list.begin();
        }
        return ret;
    }
    
    void put(int key, int value) {
        auto iter = _cache_map.find(key);
        if (iter != _cache_map.end())
        {
            _cache_list.erase(iter->second);
            _cache_list.emplace_front(key, value);
            iter->second = _cache_list.begin();
        }
        else
        {
            int len = _cache_map.size();
            if (len < _capacity)
            {
                _cache_list.emplace_front(key, value);
                _cache_map[key] = _cache_list.begin();
            }
            else
            {
                int bk_key = _cache_list.back().first;
                auto bk_iter = _cache_map.find(bk_key);
                _cache_list.erase(bk_iter->second);
                _cache_map.erase(bk_iter);
                _cache_list.emplace_front(key, value);
                _cache_map[key] = _cache_list.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }