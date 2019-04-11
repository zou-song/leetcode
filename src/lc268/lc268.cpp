#include "lc.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        int ret = len;
        while (idx < len)
        {
            if (nums[idx] == idx)
            {
                idx++;
            }
            else if (nums[idx] >= len || nums[idx] < 0)
            {
                ret = idx;
                idx++;
            }
            else
            {
                if (nums[idx] == nums[nums[idx]])
                {
                    ret = idx;
                    idx++;
                }
                else
                {
                    swap(nums[idx], nums[nums[idx]]);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums,line);
		cout << toString(Solution().missingNumber(nums)) << endl;
	}
	return 0;
}