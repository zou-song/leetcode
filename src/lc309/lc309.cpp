#include "lc.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)    return 0;
        vector<int> dp(len, 0);
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (prices[i] > prices[j])
                {
                    if (j - 2 < 0)
                    {
                        dp[i] = max(dp[i], prices[i] - prices[j]);
                    }
                    else
                    {
                        dp[i] = max(dp[i], prices[i] - prices[j] + dp[j - 2]);
                    }
                }
                else
                {
                    dp[i] = max(dp[i], dp[i - 1]);
                }
            }
        }
        return dp[len - 1];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> prices;
		walkString(prices, line);
		cout << toString(Solution().maxProfit(prices)) << endl;
	}
	return 0;
}