#include "lc.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int beg = -1;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] == 0)
            {
                if (beg < 0)
                    beg = i;
            }
            else
            {
                if (beg >= 0)
                {
                    swap(nums[beg], nums[i]);
                    beg++;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		Solution().moveZeroes(nums);
		cout << toString(nums) << endl;
	}
	return 0;
}