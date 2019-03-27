#include "lc.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int i = 5;
        int ret = 0;
        while (i <= n)
        {
            ret += n / i;
            if (INT_MAX / 5 < i)
                break;
            i = i * 5;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().trailingZeroes(n)) << endl;
	}
	return 0;
}