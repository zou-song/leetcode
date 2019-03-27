#include "lc.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cntMap;
        int ret = 0, maxCnt = 0;
        for (auto n : nums)
        {
            if (++cntMap[n] > maxCnt)
            {
                maxCnt = cntMap[n];
                ret = n;
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
		cout << toString(Solution().majorityElement(nums)) << endl;
	}
	return 0;
}