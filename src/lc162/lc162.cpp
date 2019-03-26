#include "lc.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len < 1)    return -1;
        if (len == 1)   return 0;
        for (int i = 1; i < len - 1; ++i)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        if (nums[0] > nums[1])
            return 0;
        if (nums[len - 1] > nums[len - 2])
            return len - 1;
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().findPeakElement(nums)) << endl;
	}
	return 0;
}