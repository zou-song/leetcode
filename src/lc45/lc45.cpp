#include "lc.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        int *tmp = new int[len];
        memset(tmp, 0, len * sizeof(int));
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] >= i - j)
                {
                    if (tmp[i] == 0)
                    {
                        tmp[i] = tmp[j] + 1;
                    }
                    else if (tmp[j] + 1 < tmp[i])
                    {
                        tmp[i] = tmp[j] + 1;
                    }
                }
            }
        }
        int ret = tmp[len - 1];
        delete[] tmp;
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().jump(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}