#include "lc.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.;
        bool neg = false;
        if (n == INT_MIN)
        {
            return 1.0 / x * myPow(x, n + 1);
        }
        if (n < 0)
        {
            neg = true;
            n = -n;
        }
        double ret = 1.0;
        if (n % 2)
        {
            ret = myPow(x, (n - 1)/ 2);
            ret = x * ret * ret;
        }
        else
        {
            ret = myPow(x, n / 2);
            ret = ret * ret;
        }
        if (neg)
            return 1.0 / ret;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		double x;
		walkString(x, line);
		getline(cin, line);
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().myPow(x, n)) << endl;
	}
	return 0;
}