#include "lc.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = 0;
        int idx = 0;
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
            if (sum >= s)
            {
                idx = i;
                break;
            }
        }
        if (sum < s)    return 0;
        int cur_len = idx + 1;
        ret = idx + 1;
        for (int i = idx + 1; i < len; ++i)
        {
            int beg = i - cur_len;
            while (sum + nums[i] >= s)
            {
                sum -= nums[beg];
                beg++;
            }
            sum += nums[--beg];
            cur_len = i - beg + 1;
            if (cur_len < ret)
                ret = cur_len;
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