#include "lc.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> tmp;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            tmp.push_back({nums[i], i});
        }
        int idx1 = 0, idx2 = len - 1;
        sort(tmp.begin(), tmp.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.first < rhs.first;
        });
        while (idx1 < idx2)
        {
            if(tmp[idx1].first + tmp[idx2].first == target)
                return {tmp[idx1].second, tmp[idx2].second};
            else if(tmp[idx1].first + tmp[idx2].first < target)
            {
                idx1++;
            }
            else
            {
                idx2--;
            }
        }
        return {0, 0};
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}