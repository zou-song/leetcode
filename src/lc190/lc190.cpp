#include "lc.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret;
        for (int i = 0; i < 32; ++i)
        {
            int j = n % 2;
            n /= 2;
            ret = ret * 2 + j;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		uint32_t n = 0;
		walkString(n, line);
		cout << toString(Solution().reverseBits(n)) << endl;
	}
	return 0;
}