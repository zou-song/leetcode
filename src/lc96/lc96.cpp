#include "lc.h"

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        vector<int> tmp(n + 1);
        tmp[0] = tmp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                tmp[i] += (tmp[j - 1] * tmp[i - j]);
        }
        return tmp[n];
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}