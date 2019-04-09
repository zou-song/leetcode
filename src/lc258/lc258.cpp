#include "lc.h"

class Solution {
public:
    int addDigits(int num) {
        while (num / 10)
        {
            int n = 0;
            while (num)
            {
                n += (num % 10);
                num /= 10;
            }
            num = n;
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int num = 0;
		walkString(num, line);
		cout << toString(Solution().addDigits(num)) << endl;
	}
	return 0;
}