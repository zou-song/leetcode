#include "lc.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        while (j < len)
        {
            if (nums[j] < 1 || nums[j] > j + 1)
            {
                ++j;
            }
            else if (nums[nums[j] - 1] = nums[j])
            {
                ++j;
            }
            else
                swap(nums[nums[j] - 1], nums[j]);
        }
        int i = 0;
        for ( ; i < len; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return i + 1;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}