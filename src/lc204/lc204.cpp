#include "lc.h"

class Solution {
public:
    int countPrimes(int n) {
        vector<int> tmp(n, 1);
        int cnt = 0;
        for (int i = 2; i < n; ++i)
        {
            if (tmp[i])
            {
                cnt++;
                for (int j = 2; i * j < n; ++j)
                    tmp[i * j] = 0;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().countPrimes(n)) << endl;
	}
	return 0;
}