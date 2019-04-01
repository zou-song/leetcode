#include "lc.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = 0;
        int ret = 0;
        while (n > 0)
        {
            if (m == n && (m % 2))
            {
                ret = ret + (1 << bit);
            }
            bit++;
            m /= 2;
            n /= 2;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int m = 0;
		walkString(m, line);
		getline(cin, line);
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().rangeBitwiseAnd(m, n)) << endl;
	}
	return 0;
}