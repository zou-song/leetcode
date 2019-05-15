#include "lc.h"

class RandomizedSet {
    unordered_map<int, int> _hashmap;
    vector<int> _vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter = _hashmap.find(val);
        if (iter == _hashmap.end())
        {
            _hashmap[val] = _vec.size();
            _vec.emplace_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = _hashmap.find(val);
        if (iter != _hashmap.end())
        {
            int idx = iter->second;
            swap(_vec[idx], _vec.back());
            _hashmap[_vec[idx]] = idx;
            _vec.pop_back();
            _hashmap.erase(iter);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (_vec.size() > 0)
        {
            int idx = rand() % _vec.size();
            return _vec[idx];
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }