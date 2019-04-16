#include "lc.h"

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().canWinNim(n)) << endl;
	}
	return 0;
}
