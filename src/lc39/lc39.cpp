#include "lc.h"

class Solution {
public:
    void func(const vector<int>& candidates, int idx, int pre_sum, int target, vector<int> &vec, vector<vector<int>> &ret)
    {
        if (pre_sum > target)
            return;
        else if (pre_sum == target)
        {
            ret.push_back(vec);
            return;
        }
        int len = candidates.size();
        for (int i = idx; i < len; ++i)
        {
            vec.push_back(candidates[i]);
            func(candidates, i, pre_sum + candidates[i], target, vec, ret);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> vec;
        func(candidates, 0, 0, target, vec, ret);
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
        vector<int> candidates = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        vector<vector<int>> output = Solution().combinationSum(candidates, target);
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