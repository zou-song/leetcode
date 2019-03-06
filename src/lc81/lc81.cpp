#include "lc.h"

class Solution {
public:
    bool sequentialSearch(const vector<int>& nums, int beg, int end, int target)
    {
        for (int i = beg; i <= end; ++i)
            if (nums[i] == target)
                return true;
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int beg = 0, end = len - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[beg] && nums[mid] == nums[end])
                return sequentialSearch(nums, beg, end, target);
            if (nums[mid] >= nums[beg])
            {
                if (nums[mid] <= nums[end])
                {
                    if (nums[mid] < target)
                        beg = mid + 1;
                    else
                        end = mid - 1;
                }
                else
                {
                    if (nums[mid] < target)
                        beg = mid + 1;
                    else
                    {
                        if (nums[end] < target)
                            end = mid - 1;
                        else
                            beg = mid + 1;
                    }
                }
            }
            else
            {
                if (nums[mid] > target)
                    end = mid - 1;
                else
                {
                    if (nums[end] < target)
                        end = mid - 1;
                    else
                        beg = mid + 1;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}