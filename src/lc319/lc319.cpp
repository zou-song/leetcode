#include "lc.h"

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().bulbSwitch(n)) << endl;
	}
	return 0;
}