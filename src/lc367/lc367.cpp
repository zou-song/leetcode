#include "lc.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long xn = num / 2 + 1;
        long long pre1 = xn, pre2 = xn;
        while (true)
        {
            if (xn * xn == (long long)num)
            {
                return true;
            }
            pre2 = pre1;
            pre1 = xn;
            xn = (xn * xn + num) / (2 * xn);
            if (xn == pre1 || xn == pre2)
            {
                return false;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int num = 0;
		walkString(num, line);
		cout << toString(Solution().isPerfectSquare(num)) << endl;
	}
	return 0;
}
