#include "lc.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int beg = 0, end = len - 1;
        while (beg < end)
        {
            int mid = (beg + end) / 2;
            if (nums[beg] <= nums[mid] && nums[mid] <= nums[end])
                return nums[beg];
            if (nums[mid] >= nums[beg])
            {
                if (mid + 1 < len && nums[mid + 1] < nums[mid])
                    return nums[mid + 1];
                beg = mid + 1;
            }
            else
            {
                if (mid - 1 >= 0 && nums[mid - 1] > nums[mid])
                    return nums[mid];
                end = mid - 1;
            }
        }
        return nums[beg];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().findMin(nums)) << endl;
	}
	return 0;
}