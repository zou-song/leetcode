#include "lc.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int n : nums)
        {
            int three = twice & n;
            twice = twice ^ three;
            n = n ^ three;
            int two = once & n;
            twice = twice | two;
            once = once ^ two;
            n = n ^ two;
            once = once | n;
        }
        return once;
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