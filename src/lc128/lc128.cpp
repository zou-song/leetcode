#include "lc.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tmpSet;
        for (int n : nums)
            tmpSet.insert(n);
        int ret = 0;
        for (int n : tmpSet)
        {
            if (tmpSet.count(n - 1) == 0)
            {
                int curNum = 0;
                while (tmpSet.count(n))
                {
                    curNum++;
                    n++;
                }
                if (curNum > ret)   ret = curNum;
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
		std::vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().longestConsecutive(nums)) << endl;
	}
	return 0;
}