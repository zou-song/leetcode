#include "lc.h"

class Solution {
public:
    vector<vector<int>> lexicoGraphicPermute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ret;
        ret.push_back(nums);
        while (true)
        {
            auto vec = ret.back();
            int idx = len - 2;
            while (idx >= 0 && vec[idx] >= vec[idx + 1])
            {
                idx--;
            }
            if (idx < 0)
                break;
            int j = len - 1;
            while (vec[j] <= vec[idx])
                j--;
            swap(vec[idx], vec[j]);
            int i = idx + 1, k = len - 1;
            while (i < k)
            {
                swap(vec[i], vec[k]);
                i++;
                k--;
            }
            ret.push_back(vec);
        }
        return ret;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return lexicoGraphicPermute(nums);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().permuteUnique(nums)) << endl;
	}
	return 0;
}
