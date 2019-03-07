#include "lc.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};
        vector<int> ret = {0, 1};
        for (int i = 2; i <= n; ++i)
        {
            int len = ret.size();
            for (int j = len - 1; j >= 0; --j)
            {
                ret.push_back((1 << (i - 1)) | ret[j]);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}