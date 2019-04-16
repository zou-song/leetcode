#include "lc.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)   return 0;
        vector<int> dp(len);
        dp[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << (toString(Solution().lengthOfLIS(nums))) << endl;
	}
	return 0;
}