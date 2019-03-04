#include "lc.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len < 1)    return 0;
        int tmp = nums[0];
        int ret = tmp;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] + tmp > nums[i])
            {
                tmp = nums[i] + tmp;
            }
            else
            {
                tmp = nums[i];
            }
            if (ret < tmp)  ret = tmp;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
