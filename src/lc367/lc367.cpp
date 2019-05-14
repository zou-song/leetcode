#include "lc.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int xn = num;
        unsigned int diff = UINT_MAX;
        while (xn > 0)
        {
            unsigned int tmp = 0;
            if (xn * xn > num)
            {
                tmp = xn * xn - num;
            }
            else if (xn * xn == num)
            {
                return true;
            }
            else
            {
                tmp = num - xn * xn;
            }
            if (tmp > diff)
            {
                return false;
            }
            diff = tmp;
            xn = (xn * xn + num) / (2 * xn);
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