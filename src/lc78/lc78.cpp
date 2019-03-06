#include "lc.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        ret.push_back({});
        for (auto n : nums)
        {
            size_t len = ret.size();
            for (size_t i = 0; i < len; ++i)
            {
                vector<int> tmp = ret[i];
                tmp.push_back(n);
                ret.push_back(tmp);
            }
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
		vector<vector<int>> output = Solution().subsets(input);
		cout << toString(output) << endl;
	}
	return 0;
}