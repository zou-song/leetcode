#include "lc.h"

class NumArray {
    vector<int> _nums;
    vector<int> _cache;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
            _cache.push_back(sum);
            _nums.push_back(n);
        }
    }
    
    void update(int i, int val) {
        int diff = val - _nums[i];
        int len = _nums.size();
        for (int j = i; j < len; ++j)
        {
            _cache[j] += diff;
        }
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
        {
            return _cache[j];
        }
        return _cache[j] - _cache[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }