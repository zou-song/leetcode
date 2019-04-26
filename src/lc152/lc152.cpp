#include "lc.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        typedef pair<long long, int> PAIR;
        vector<PAIR> dp(len);
        if (len <= 0)   return 0;
        dp.emplace_back(nums[0], 1);
        long long ret = nums[0];
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] == 0)
            {
                dp[i] = PAIR(0, 1);
            }
            else if (nums[i] > 0)
            {
                long long tmp = nums[i];
                dp[i] = PAIR(tmp, 1);
                int idx = i - 1;
                bool neg = false;
                while (idx >= 0)
                {
                    if (dp[idx].first == 0)
                    {
                        break;
                    }
                    else if (dp[idx].first < 0)
                    {
                        neg = !neg;
                    }
                    tmp *= dp[idx].first;
                    if (!neg)
                    {
                        dp[i] = PAIR(tmp, i - idx + dp[idx].second);
                    }
                    idx = idx - dp[idx].second;
                }
            }
            else
            {
                long long tmp = nums[i];
                dp[i] = PAIR(tmp, 1);
                int idx = i - 1;
                bool neg = true;
                while (idx >= 0)
                {
                    if (dp[idx].first == 0)
                    {
                        if (dp[i].first > 0)
                        {
                            break;
                        }
                        else
                        {
                            dp[i] = PAIR(0, i - idx + dp[idx].second);
                            break;
                        }
                    }
                    else if (dp[idx].first < 0)
                    {
                        neg = !neg;
                    }
                    tmp *= dp[idx].first;
                    if (!neg)
                    {
                        dp[i] = PAIR(tmp, i - idx + dp[idx].second);
                    }
                    idx = idx - dp[idx].second;
                }
            }
            if (ret < dp[i].first)
            {
                ret = dp[i].first;
            }
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
		cout << toString(Solution().maxProduct(nums)) << endl;
	}
	return 0;
}