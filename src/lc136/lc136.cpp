#include "lc.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
        {
            ret = ret ^ n;
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
		walkString(nums, line);
		cout << toString(Solution().singleNumber(nums)) << endl;
	}
	return 0;
}