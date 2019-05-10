#include "lc.h"

class Solution {
public:
    int integerBreak(int n) {
        if (n < 2)
        {
            return 0;
        }
        if (n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 2;
        }
        vector<int> dp(n + 1, 1);
        dp[2] = 2;  dp[3] = 3;
        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().integerBreak(n)) << endl;
	}
	return 0;
}