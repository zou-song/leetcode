#include "lc.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int len = nums.size();
        bool *tmp = new bool[len];
        memset(tmp, false, len * sizeof(bool));
        tmp[0] = true;
        for (int i = 1; i < len; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (tmp[j] && nums[j] >= i - j)
                {
                    tmp[i] = true;
                    break;
                }
            }
        }
        bool ret = tmp[len - 1];
        delete[] tmp;
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}