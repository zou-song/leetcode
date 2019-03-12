#include "lc.h"

class Solution {
public:
    void func(const vector<int>& nums, int target, int idx, int n, vector<vector<int>>& ret, vector<int> vec)
    {
        if(target == 0 && n == 0)
        {
            ret.push_back(vec);
            return;
        }
        if (n < 0)
            return;
        int len = nums.size();
        if (idx >= len)
            return;
        int idx2 = idx;
        while (idx2 < len && nums[idx2] == nums[idx])
            idx2++;
        func(nums, target, idx2, n, ret, vec);
        for (int i = idx, j = 0; i < idx2 && j < n; ++i, ++j)
        {
            target = target - nums[i];
            vec.push_back(nums[i]);
            func(nums, target, idx2, --n, ret, vec);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> vec;
        func(nums, target, 0, 4, ret, vec);
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		getline(cin, line);
		int target = 0;
		walkString(target, line);
		auto output = Solution().fourSum(nums, target);
		cout << toString(output) << endl;
	}
	return 0;
}