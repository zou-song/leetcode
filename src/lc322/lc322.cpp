#include "lc.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i)
        {
            dp[i] = INT_MAX;
            for (int ci : coins)
            {
                if (i - ci < 0)
                {
                    break;
                }
                else if (dp[i - ci] == INT_MAX)
                {
                    dp[i] = INT_MAX;
                }
                else
                {
                    dp[i] = min(dp[i], dp[i - ci] + 1);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> coins;
		walkString(coins, line);
		getline(cin, line);
		int amount = 0;
		walkString(amount, line);
		cout << toString(Solution().coinChange(coins, amount)) << endl;
	}
	return 0;
}