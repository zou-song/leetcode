#include "lc.h"

class Solution {
    const static int SIZE = 128;
public:
    string convertToTitle(int n) {
        string ret(SIZE, 0);
        int idx = SIZE - 1;
        while (n)
        {
            int i = n % 26;
            if (i == 0)
            {
                ret[idx--] = 'Z';
                n = n / 26 - 1;
            }
            else
            {
                ret[idx--] = 'A' + i - 1;
                n = n / 26;
            }
        }
        return ret.substr(idx + 1);
    }
};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        int n = 0;
        walkString(n, line);
        cout << toString(Solution().convertToTitle(n)) << endl;
    }
    return 0;
}