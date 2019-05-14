#include "lc.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len <= 0)
        {
            return {};
        }
        vector<vector<int>> dp(len);
        dp[0].emplace_back(nums[0]);
        for (int i = 1; i < len; ++i)
        {
            dp[i].emplace_back(nums[i]);
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size())
                {
                    dp[i] = dp[j];
                    dp[i].emplace_back(nums[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs.size() < rhs.size();
        });
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().largestDivisibleSubset(nums)) << endl;
	}
	return 0;
}