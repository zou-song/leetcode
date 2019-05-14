#include "lc.h"

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int x = a & b;
        unsigned int y = a ^ b;
        while (x)
        {
            unsigned int tmp = (x << 1);
            x = tmp & y;
            y = tmp ^ y;
        }
        return (x | y);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int a = 0, b = 0;
		walkString(a, line);
		getline(cin, line);
		walkString(b, line);
		cout << toString(Solution().getSum(a, b)) << endl;
	}
	return 0;
}