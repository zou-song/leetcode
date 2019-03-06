#include "lc.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        int idx = 0;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] == nums[idx])
            {
                if (idx <= 0 || nums[idx - 1] != nums[idx])
                {
                    nums[++idx] = nums[i];
                }
            }
            else
            {
                nums[++idx] = nums[i];
            }
        }
        return idx + 1;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}