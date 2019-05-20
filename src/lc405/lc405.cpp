#include "lc.h"

class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        string ret;
        if (n == 0)
        {
            return "0";
        }
        while (n)
        {
            int a = n % 16;
            char c;
            if (a > 9)
            {
                c = a - 10 + 'a';
            }
            else
            {
                c = a + '0';
            }
            ret = c + ret;
            n /= 16;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int num = 0;
		walkString(num, line);
		cout << toString(Solution().toHex(num)) << endl;
	}
	return 0;
}