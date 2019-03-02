#include "lc.h"

class Solution {
public:
    int halfSearch(const vector<int>& nums, int beg, int end, int target)
    {
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
        return  -1;
    }
    
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int beg = 0, end = len - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[beg] <= nums[mid])
            {
                if (nums[mid] <= nums[end])
                    return halfSearch(nums, beg, end, target);
                if (nums[mid] < target)
                {
                    beg = mid + 1;
                }
                else
                {
                    if (target > nums[end])
                        return halfSearch(nums, beg, mid - 1, target);
                    else
                    {
                        beg = mid + 1;
                    }
                }
            }
            else
            {
                if (nums[mid] < target)
                {
                    if (target > nums[end])
                    {
                        end = mid - 1;
                    }
                    else
                        return halfSearch(nums, mid + 1, end, target);
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
	string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}