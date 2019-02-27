#include "lc.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;
        size_t len = nums.size();
        for (size_t i = 0; i < len; ++i)
        {
            if (nums[i] != val)
            {
                nums[ret++] = nums[i];
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int val = stringToInteger(line);
        
        int ret = Solution().removeElement(nums, val);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}