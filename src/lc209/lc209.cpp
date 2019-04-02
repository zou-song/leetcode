#include "lc.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = 0;
        int idx = 0;
        int len = nums.size();
        int sum = 0;
        int beg = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
            if (sum >= s)
            {
                idx = i;
                break;
            }
        }
        if (sum < s)    return ret;
        for (int i = 0; i <= idx; ++i)
        {
            if (sum - nums[i] < s)
            {
                break;
            }
            sum -= nums[i];
            beg = i + 1;
        }
        ret = idx - beg + 1;
        for (int i = idx + 1; i < len; ++i)
        {
            sum += nums[i];
            for (int j = beg; j <= i; ++j)
            {
                if (sum - nums[j] < s)
                    break;
                sum -= nums[j];
                beg = j + 1;
            }
            if (i - beg + 1 < ret)
                ret = i - beg + 1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        int s = 0;
        walkString(s, line);
        getline(cin, line);
        vector<int> nums;
        walkString(nums, line);
        cout << toString(Solution().minSubArrayLen(s, nums)) << endl;
    }
    return 0;
}