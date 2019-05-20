#include "lc.h"

class Solution {
    unordered_map<int, vector<int>> _hashmap;
public:
    Solution(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            _hashmap[nums[i]].emplace_back(i);
        }
        srand(time(0));
    }
    
    int pick(int target) {
        auto iter = _hashmap.find(target);
        int idx = rand() % iter->second.size();
        return iter->second[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }