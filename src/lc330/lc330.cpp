#include "lc.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        if (n <= 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret = 0;
        int len = nums.size();
        int idx = 0;
        unsigned int sum = 1;
        if (!nums.empty() && nums.front() == 1)
        {
            idx++;
        }
        else
        {
            ret++;
        }
        while (sum < (unsigned int)n)
        {
            if (idx < len && nums[idx] <= sum + 1)
            {
                sum += nums[idx++];
            }
            else
            {
                sum += (sum + 1);
                ret++;
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
		walkString(nums, line);
		int n = 0;
		getline(cin, line);
		walkString(n, line);
		cout << toString(Solution().minPatches(nums, n)) << endl;
	}
	return 0;
}