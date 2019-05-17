#include "lc.h"

class Solution {
    #define LEFT true
    #define RIGHT false
    #define ODD true
    #define EVEN false
public:
    int lastRemaining(int n) {
        vector<pair<bool, bool>> tmp;
        while (n)
        {
            if (n % 2)
            {
                if (tmp.empty() || tmp.back().second == RIGHT)
                {
                    tmp.emplace_back(EVEN, LEFT);
                }
                else
                {
                    tmp.emplace_back(EVEN, RIGHT);
                }
            }
            else
            {
                if (tmp.empty() || tmp.back().second == RIGHT)
                {
                    tmp.emplace_back(ODD, LEFT);
                }
                else
                {
                    tmp.emplace_back(ODD, RIGHT);
                }
            }
            n = n / 2;
        }
        int ret = 1;
        int idx = tmp.size() - 1;
        while (idx >= 0)
        {
            if (tmp[idx].first == ODD)
            {
                ret = ret * 2;
            }
            else
            {
                if (tmp[idx].second == LEFT)
                {
                    ret = ret * 2;
                }
                else
                {
                    ret = ret * 2 - 1;
                }
            }
            idx--;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().lastRemaining(n)) << endl;
	}
	return 0;
}