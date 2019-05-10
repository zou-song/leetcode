#include "lc.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX;
        for (int n : nums)
        {
            if (n > s2)
            {
                return true;
            }
            else if (n > s1)
            {
                s2 = n;
            }
            else if (n > s3)
            {
                s1 = s3;
                s2 = n;
                s3 = INT_MAX;
            }
            else if (n <= s3)
            {
                s3 = n;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().increasingTriplet(nums)) << endl;
	}
	return 0;
}