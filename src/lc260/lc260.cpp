#include "lc.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (int n : nums)
            tmp ^= n;
        int x = ((tmp ^ (tmp - 1)) + 1) >> 1;
        int n1 = tmp;
        for (int n : nums)
            if (n & x)
                n1 ^= n;
        int n2 = tmp ^ n1;
        vector<int> ret = {n1, n2};
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
