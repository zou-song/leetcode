#include "lc.h"

class NumArray {
    vector<int> _cache;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
            _cache.push_back(sum);
        }
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
 * int param_1 = obj->sumRange(i,j);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }