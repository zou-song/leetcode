#include "lc.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        vector<int> tmp(n + 1);
        tmp[1] = 1; tmp[2] = 2;
        for (int i = 3; i <= n; ++i)
            tmp[i] = tmp[i - 1] + tmp[i - 2];
        return tmp[n];
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}