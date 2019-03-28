#include "lc.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            int j = i - 2;
            int max = 0;
            while (j >= 0)
            {
                if (dp[j] > max)
                    max = dp[j];
                j--;
            }
            dp[i] = max + nums[i];
            if (dp[i] > ret)
                ret = dp[i];
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