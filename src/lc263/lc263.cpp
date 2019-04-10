#include "lc.h"

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;
        if (num % 5 == 0)
            return isUgly(num / 5);
        if (num % 3 == 0)
            return isUgly(num / 3);
        if (num % 2 == 0)
            return isUgly(num / 2);
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
		cout << toString(Solution().isUgly(num)) << endl;
	}
	return 0;
}