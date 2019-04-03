#include "lc.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> tmp(3, 0);
        int len = nums.size();
        if (len == 1)   return nums[0];
        int ret = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            int cur_sum = max(tmp[0], tmp[1]) + nums[i];
            tmp[0] = tmp[1];
            tmp[1] = tmp[2];
            tmp[2] = cur_sum;
            if (cur_sum > ret)
                ret = cur_sum;
        }
        fill(tmp.begin(), tmp.end(), 0);
        for (int i = 1; i < len; ++i)
        {
            int cur_sum = max(tmp[0], tmp[1]) + nums[i];
            tmp[0] = tmp[1];
            tmp[1] = tmp[2];
            tmp[2] = cur_sum;
            if (cur_sum > ret)
                ret = cur_sum;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().rob(nums)) << endl;
	}
	return 0;
}