#include "lc.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int tmp = INT_MAX;
        for (int i = 0; i + 2 < len; ++i)
        {
            int n1 = nums[i];
            int nt = target - n1;
            int idx1 = i + 1, idx2 = len - 1;
            while (idx1 < idx2)
            {
                if (nums[idx1] + nums[idx2] == nt)
                    return target;
                else if (nums[idx1] + nums[idx2] < nt)
                {   
                    int sum = n1 + nums[idx1] + nums[idx2];
                    if (target - sum < tmp)
                    {
                        tmp = target - sum;
                        ret = sum;
                    }
                    idx1++;
                }
                else
                {
                    int sum = n1 + nums[idx1] + nums[idx2];
                    if (sum - target < tmp)
                    {
                        tmp = sum - target;
                        ret = sum;
                    }
                    idx2--;
                }
            }
        }
        return ret;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}