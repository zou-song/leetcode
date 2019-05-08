#include "lc.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; ++i)
        {
            dp[i] = amount + 1;
            for (int ci : coins)
            {
                if (i >= ci)
                {
                    dp[i] = min(dp[i], dp[i - ci] + 1);
                }
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
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