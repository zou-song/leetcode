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
            if (idx != last_idx)
            {
                int back_val = vec.back();
                vec[idx] = back_val;
                auto last_val_iter = hashmap.find(back_val);
                last_val_iter->second.erase(last_idx);
                last_val_iter->second.insert(idx);
            }
            vec.pop_back();
            iter->second.erase(iter->second.begin());
            if (iter->second.empty())
            {
                hashmap.erase(iter);
            }
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
 	RandomizedCollection obj;
 	bool param_1 = obj.insert(0);
 	bool param_2 = obj.insert(1);
 	bool param_3 = obj.insert(2);
 	bool param_4 = obj.insert(3);
 	bool param_5 = obj.insert(3);
 	bool param_6 = obj.remove(2);
 	bool param_7 = obj.remove(3);
 	bool param_8 = obj.remove(0);
 	int param_9 = obj.getRandom();
 	int param_10 = obj.getRandom();
 	int param_11 = obj.getRandom();
 	int param_12 = obj.getRandom();
 	return 0;
 }