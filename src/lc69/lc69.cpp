#include "lc.h"

class Solution {
public:
    int mySqrt(int x) {
        //Newton's method
        long long tmp = x;
        while (tmp * tmp > x)
        {
            tmp = (tmp + x / tmp) / 2;
        }
        return tmp;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}