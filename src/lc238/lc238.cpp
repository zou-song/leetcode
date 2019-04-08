#include "lc.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int dp = 1;
        int len = nums.size();
        vector<int> ret;
        if (len <= 0)   return ret;
        ret.push_back(1);
        for (int i = 1; i < len; ++i)
        {
            dp = dp * nums[i - 1];
            ret.push_back(dp);
        }
        dp = 1;
        for (int i = len - 2; i >= 0; --i)
        {
            dp = dp * nums[i + 1];
            ret[i] = ret[i] * dp;
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
		cout << toString(Solution().productExceptSelf(nums)) << endl;
	}
	return 0;
}