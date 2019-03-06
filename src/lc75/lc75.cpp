#include "lc.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int idx1 = 0, idx2 = len - 1;
        int idx = 0;
        while (idx <= idx2 && idx1 <= idx2)
        {
            if (nums[idx] == 0)
            {
                swap(nums[idx], nums[idx1++]);
                if (idx <= idx1)
                    idx = idx1;
            }
            else if (nums[idx] == 2)
            {
                swap(nums[idx], nums[idx2--]);
            }
            else
            {
                idx++;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().sortColors(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}