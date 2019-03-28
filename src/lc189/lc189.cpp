#include "lc.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int pre_len = len - k;
        for (int i = 0, j = pre_len - 1; i < j; ++i, --j)
        {
            swap(nums[i], nums[j]);
        }
        for (int i = pre_len, j = len - 1; i < j; ++i, --j)
        {
            swap(nums[i], nums[j]);
        }
        for (int i = 0, j = len - 1; i < j; ++i, --j)
        {
            swap(nums[i], nums[j]);
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
		getline(cin, line);
		int k = 0;
		walkString(k, line);
		Solution().rotate(nums, k);
		cout << toString(nums) << endl;
	}
	return 0;
}