#include "lc.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = {0};
        int idx = 0, len = 1;
        for (int i = 1; i <= num; ++i)
        {
            if (idx >= len)
            {
                idx = 0;
                len = ret.size();
            }
            ret.push_back(ret[idx++] + 1);
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
		cout << toString(Solution().countBits(num)) << endl;
	}
	return 0;
}