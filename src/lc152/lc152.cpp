#include "lc.h"

class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)   return 0;
        vector<long long> dp(len);
        dp[0] = nums[0];
        long long ret = dp[0];
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] == 0)
            {
                dp[i] = 0;
            }
            else if (nums[i] > 0)
            {
                int idx = i - 1;
                dp[i] = nums[i];
                long long tmp = nums[i];
                while (idx >= 0)
                {
                    if (dp[idx] > 0 && tmp > 0)
                    {
                        dp[i] = tmp * dp[idx];
                        break;
                    }
                    else if (nums[idx] == 0)
                    {
                        break;
                    }
                    else
                    {
                        tmp *= nums[idx--];
                        if (tmp > 0)
                        {
                            dp[i] = tmp;
                        }
                    }
                }
            }
            else
            {
                int idx = i - 1;
                dp[i] = nums[i];
                long long tmp = nums[i];
                while (idx >= 0)
                {
                    if (dp[idx] > 0 && tmp > 0)
                    {
                        dp[i] = tmp * dp[idx];
                        break;
                    }
                    else if (nums[idx] == 0)
                    {
                        if (dp[i] < 0)
                        {
                            dp[i] = 0;
                        }
                        break;
                    }
                    else
                    {
                        tmp *= nums[idx--];
                        if (tmp > 0)
                        {
                            dp[i] = tmp;
                        }
                    }
                }
            }
            if (ret < dp[i])
            {
                ret = dp[i];
            }
        }
        return ret;
    }
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)   return 0;
        long long tmax = nums[0], tmin = nums[0];
        long long ret = nums[0];
        for (int i = 1; i < len; ++i)
        {
            long long tmp = tmax;
            tmax = max((long long)nums[i], max(tmax * nums[i], tmin * nums[i]));
            tmin = min((long long)nums[i], min(tmp * nums[i], tmin * nums[i]));
            ret = max(tmax, max(tmin, ret));
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