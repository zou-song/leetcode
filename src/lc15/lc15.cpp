#include "lc.h"

class Solution {
public:
    int halfSearch(const vector<int>& nums, int beg, int end, int target)
    {
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        for (int idx1 = 0; idx1 < len && nums[idx1] <= 0; )
        {
            int ln = nums[idx1];
            for (int idx2 = len - 1; idx2 > idx1 && nums[idx2] >= 0; )
            {
                int rn = nums[idx2];
                int target = 0 - ln - rn;
                if (target < nums[idx1] || target > nums[idx2])
                    break;
                int idx = halfSearch(nums, idx1 + 1, idx2 - 1, target);
                if (idx > idx1)
                    ret.push_back({nums[idx1], nums[idx], nums[idx2]});
                while (idx2 > idx1 && nums[idx2] >= 0 && nums[idx2] == rn)
                    idx2--;
            }
            while (idx1 < len && nums[idx1] <= 0 && nums[idx1] == ln)
                idx1++;
        }
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<int> input;
		walkString(input, line);
		auto output = Solution().threeSum(input);
		cout << toString(output) << endl;
	}
	return 0;
}