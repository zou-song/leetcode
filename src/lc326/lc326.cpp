#include "lc.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n % 3)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().isPowerOfThree(n)) << endl;
	}
	return 0;
}