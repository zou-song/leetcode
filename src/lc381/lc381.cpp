#include "lc.h"

class RandomizedCollection {
    unordered_map<int, unordered_set<int>> hashmap;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto iter = hashmap.find(val);
        if (iter != hashmap.end())
        {
            iter->second.emplace(vec.size());
            vec.emplace_back(val);
            return false;
        }
        hashmap[val].emplace(vec.size());
        vec.emplace_back(val);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = hashmap.find(val);
        if (iter != hashmap.end())
        {
            int idx = *(iter->second.begin());
            int last_idx = vec.size() - 1;
            if (idx == last_idx || vec[idx] == vec[last_idx])
            {
                iter->second.erase(last_idx);
            }
            else
            {
                int back_val = vec.back();
                vec[idx] = back_val;
                auto last_val_iter = hashmap.find(back_val);
                last_val_iter->second.erase(last_idx);
                last_val_iter->second.insert(idx);
                iter->second.erase(idx);
            }
            if (iter->second.empty())
            {
                hashmap.erase(iter);
            }
            vec.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (vec.size() > 0)
        {
            int idx = rand() % vec.size();
            return vec[idx];
        }
        return 0;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 int main(int argc, char const *argv[])
 {
 	/*code*/
 	return 0;
 }
