#include "lc.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        while (i >= 0)
        {
            int j = i + 1;
            while (j < len && nums[j] > nums[i])
            {
                ++j;
            }
            if (j == i + 1)
            {
                --i;
            }
            else if (nums[j - 1] > nums[i])
            {
                swap(nums[j - 1], nums[i]);
                //reverse
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
            else
            {
                --i;
            }
        }
        if (i < 0)
            reverse(nums.begin(), nums.end());
    }
};

int main(int argc, char *argv[])
{
	string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
	return 0;
}