#include "lc.h"

class Solution {
public:
    void permute(vector<int>& nums, int idx, vector<vector<int>>& ret, vector<int> &vec)
    {
        if (idx >= nums.size())
        {
            ret.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); ++i)
        {
            swap(nums[i], nums[idx]);
            vec.push_back(nums[i]);
            permute(nums, idx + 1, ret, vec);
            vec.pop_back();
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        permute(nums, 0, ret, vec);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line))
    {
        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        vector<int> nums = stringToIntegerVector(line);
        vector<vector<int>> output = Solution().permute(nums);
        cout << "[\n";
        for (auto &vec : output)
        {
            string str = integerVectorToString(vec);
            cout << str << endl;
        }
        cout << "]\n";
    }
    return 0;
}