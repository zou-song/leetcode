#include "lc.h"

class Solution {
public:
    bool isPowerOfFour(int num) {
        int k = 0;
        if (num <= 0)    return false;
        if (num == 1)   return true;
        while (num != 1)
        {
            if (num % 2)
            {
                return false;
            }
            num /= 2;
            k++;
        }
        if (k % 2)
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int num = 0;
		walkString(num, line);
		cout << toString(Solution().isPowerOfFour(num)) << endl;
	}
	return 0;
}