#include "lc.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
    
        int len = nums.size();
        for (int i = 0; i < len - 3; ++i)
        {
            for (int j = i + 1; j < len - 2; ++j)
            {
                int sum = target - nums[i] - nums[j];
                int front = j + 1, back = len - 1;
                while (front < back)
                {
                    int a = nums[front] + nums[back];
    
                    if (a < sum)    front++;
                    else if (a > sum)   back--;
                    else
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]); tmp.push_back(nums[j]); tmp.push_back(nums[front]); tmp.push_back(nums[back]);
                        result.push_back(tmp);
    
                        while (front < back && nums[front] == tmp[2])   front++;
                        while (front < back && nums[back] == tmp[3])    back--;
                    }
                }
    
                while (j < len - 1 && nums[j+1] == nums[j]) j++;
            }
    
            while (i < len - 1 && nums[i + 1] == nums[i])   i++;
        }
    
        return result;
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