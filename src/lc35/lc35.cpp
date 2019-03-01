#include "lc.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int beg = 0, end = len - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (beg >= len)
            return len;
        if (end < 0)
            return 0;
        return beg;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}