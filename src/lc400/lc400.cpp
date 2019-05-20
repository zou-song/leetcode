#include "lc.h"

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)
        {
            return n;
        }
        long long k = 2, b = 10;
        n -= 9;
        while ((long long)n > 9 * k * b)
        {
            n = n - 9 * k * b;
            k++;
            b *= 10;
        }
        int pre = (n - 1) / (k * b) + 1;
        n = n - (pre - 1) * (k * b);
        int last = (n - 1) / k;
        int idx = n % k;
        if (idx == 0)
        {
            idx = k;
        }
        else if (idx == 1)
        {
            return pre;
        }
        idx = k - idx;
        while (idx > 0)
        {
            last = last / 10;
            idx--;
        }
        return last % 10;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().findNthDigit(n)) << endl;
	}
	return 0;
}