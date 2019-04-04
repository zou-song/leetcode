#include "lc.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int len = nums.size();
        int idx = 0;
        while (idx < len)
        {
            int beg = nums[idx];
            while (idx + 1 < len && nums[idx + 1] == nums[idx] + 1)
            {
                idx++;
            }
            int end = nums[idx];
            string s;
            if (beg == end)
                s = to_string(beg);
            else
                s = to_string(beg) + "->" + to_string(end);
            ret.push_back(s);
            idx++;
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
		cout << toString(Solution().summaryRanges(nums)) << endl;
	}
	return 0;
}