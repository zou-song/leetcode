#include "lc.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n)
        {
            n = n & (n - 1);
            ret++;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		uint32_t n;
		walkString(n, line);
		cout << toString(Solution().hammingWeight(n)) << endl;
	}
	return 0;
}