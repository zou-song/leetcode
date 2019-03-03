#include "lc.h"

class Solution {
public:
    void func(const vector<int>& candidates, int target, int idx, vector<vector<int>> &ret, vector<int> &vec)
    {
        int len = candidates.size();
        if (target == 0)
        {
            ret.push_back(vec);
            return;
        }
        else if (target < 0 || idx >= len)
            return;
        //find the same elements
        int end_idx = idx;
        while (end_idx < len && candidates[end_idx] == candidates[idx])
        {
            ++end_idx;
        }
        for (int i = 0; i <= end_idx - idx; ++i)
        {
            for (int j = 0; j < i; ++j)
                vec.push_back(candidates[idx]);
            func(candidates, target - i * candidates[idx], end_idx, ret, vec);
            for (int j = 0; j < i; ++j)
                vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> vec;
        func(candidates, target, 0, ret, vec);
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
        vector<vector<int>> output = Solution().combinationSum2(candidates, target);
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