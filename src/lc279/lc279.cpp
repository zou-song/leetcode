#include "lc.h"

class Solution {
public:
    int numSquares(int n) {
        static unordered_map<int, int> solved_map;
        auto iter = solved_map.find(n);
        if (iter != solved_map.end())
            return iter->second;
        int q = sqrt(n);
        if (q * q == n)
        {
            solved_map[n] = 1;
            return 1;
        }
        int ret = n;
        for (int i = q; i >= 1; --i)
        {
            int k = numSquares(n - i * i);
            if (ret > 1 + k)
            {
                ret = 1 + k;
            }
            if (ret == 2)
                break;
        }
        solved_map[n] = ret;
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
		cout << toString(Solution().numSquares(n)) << endl;
	}
	return 0;
}