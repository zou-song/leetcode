#include "lc.h"

class Solution {
public:
    int findLowerBound(const vector<int>& nums, int beg, int end)
    {
        int target = nums[end];
        while (beg < end && nums[beg] != target)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid;
        }
        return beg;
    }
    
    int findUpperBound(const vector<int>& nums, int beg, int end)
    {
        int target = nums[beg];
        while (beg < end && nums[end] != target)
        {
            int mid = (beg + end + 1) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid;
            }
        }
        return end;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int beg = 0, end = len - 1;
        int lb = 0, ub = 0;
        while (beg <= end)
        {
            if (nums[beg] == target && nums[end] == target)
                break;
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
            {
                return {findLowerBound(nums, beg, mid), findUpperBound(nums, mid, end)};
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
        if (beg > end)
        {
            return {-1, -1};
        }
        return {beg, end};
    }
};

int main(int argc, char *argv[])
{
	string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}