#include "lc.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())   return ret;
        ret.push_back({});
        sort(nums.begin(), nums.end());
        size_t len = nums.size();
        size_t idx = 0;
        while (idx < len)
        {
            size_t idx2 = idx;
            while (idx2 < len && nums[idx2] == nums[idx])
                idx2++;
            size_t retlen = ret.size();
            for (size_t i = 0; i < retlen; ++i)
            {
                for (size_t j = 1; j <= idx2 - idx; ++j)
                {
                    vector<int> tmp = ret[i];
                    tmp.insert(tmp.end(), j, nums[idx]);
                    ret.push_back(tmp);
                }
            }
            idx = idx2;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> input;
		walkString(input, line);
		auto output = Solution().subsetsWithDup(input);
		cout << toString(output) << endl;
	}
	return 0;
}