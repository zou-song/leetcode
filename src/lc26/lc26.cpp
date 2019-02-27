#include "lc.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != nums[ret])
            {
                nums[++ret] = nums[i];
            }
        }
        return nums.empty() ? 0 : ret + 1;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}
