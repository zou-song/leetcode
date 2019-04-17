#include "lc.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0;
        if (dividend == INT_MIN)
        {
            if (divisor > 0)
            {
                if (divisor == 1)
                    return INT_MIN;
                dividend += divisor;
                ret++;
            }
            else
            {
                if (divisor == -1)
                    return INT_MAX;
                dividend -= divisor;
                ret++;
            }
        }
        if (divisor == INT_MIN)
        {
            return ret;
        }
        bool neg = false;
        if (dividend < 0)
        {
            dividend = -dividend;
            neg = !neg;
        }
        if (divisor < 0)
        {
            divisor = -divisor;
            neg = !neg;
        }
        while (dividend >= divisor)
        {
            int k = 0;
            int n1 = 1;
            while ((INT_MAX >> 1) >= (divisor << k) && (divisor << k) <= dividend)
            {
                n1 = n1 << 1;
                k++;
            }
            if ((INT_MAX >> 1) < (divisor << k))
            {
                if ((divisor << k) <= dividend)
                {
                    ret += n1;
                    dividend -= (divisor << k);
                }
                else
                {
                    k--;
                    n1 = n1 >> 1;
                    dividend -= (divisor << k);
                    ret += n1;
                }
            }
            else
            {
                k--;
                n1 = n1 >> 1;
                dividend -= (divisor << k);
                ret += n1;
            }
        }
        return neg ? -ret : ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int dividend = 0, divisor = 0;
		walkString(dividend, line);
		getline(cin, line);
		walkString(divisor, line);
		cout << toString(Solution().divide(dividend, divisor)) << endl;
	}
	return 0;
}