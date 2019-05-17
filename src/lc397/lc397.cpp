#include "lc.h"

class Solution {
public:
    int integerReplacement(int n) {
        if (n <= 1)
        {
            return 0;
        }
        if (n % 2 == 0)
        {
            return integerReplacement(n / 2) + 1;
        }
        return min(integerReplacement((n - 1) / 2), integerReplacement((n - 1) / 2 + 1)) + 2;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().integerReplacement(n)) << endl;
	}
	return 0;
}