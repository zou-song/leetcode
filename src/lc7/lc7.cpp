#include "lc.h"

class Solution {
public:
    int reverse(int x) {
        long long y = static_cast<long long>(x);
        bool neg = false;
        if (y < 0)
        {
            neg = true;
            y = -y;
        }
        string s;
        while (y)
        {
            s += to_string(y % 10);
            y /= 10;
        }
        if (s.empty())  s = "0";
        long long num = stoll(s);
        if (neg)    num = -num;
        if (num > INT_MAX || num < INT_MIN) return 0;
        return static_cast<int>(num);
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}