#include "lc.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)
        {
            return 0;
        }
        vector<int> ups(len, 1), downs(len, 1);
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ups[i] = downs[i - 1] + 1;
                downs[i] = downs[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                downs[i] = ups[i - 1] + 1;
                ups[i] = ups[i - 1];
            }
            else
            {
                downs[i] = downs[i - 1];
                ups[i] = ups[i - 1];
            }
        }
        return max(*max_element(ups.begin(), ups.end()), *max_element(downs.begin(), downs.end()));
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().wiggleMaxLength(nums)) << endl;
	}
	return 0;
}