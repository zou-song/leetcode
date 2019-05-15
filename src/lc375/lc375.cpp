#include "lc.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1);
        for_each(dp.begin(), dp.end(), [n](vector<int>& vec){
            vec.resize(n + 1);
        });
        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 0;
            for (int j = i - 1; j >= 1; --j)
            {
                dp[j][i] = INT_MAX;
                for (int k = j; k <= i; ++k)
                {
                    int n1 = 0, n2 = 0;
                    if (k == j)
                    {
                        n1 = 0;
                    }
                    else
                    {
                        n1 = dp[j][k - 1];
                    }
                    if (k == i)
                    {
                        n2 = 0;
                    }
                    else
                    {
                        n2 = dp[k + 1][i];
                    }
                    dp[j][i] = min(dp[j][i], k + max(n1, n2));
                }
            }
        }
        return dp[1][n];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().getMoneyAmount(n)) << endl;
	}
	return 0;
}