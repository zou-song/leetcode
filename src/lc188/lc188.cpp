#include "lc.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 0 || k <= 0)
            return 0;
        vector<int> dp(len, 0);
        for (int i = 1; i <= k && i <= len / 2; ++i)
        {
            vector<int> tmp(len, 0);
            bool changed = false;
            int tmpmax = -prices[0];
            for (int j = 1; j < len; ++j)
            {
                tmp[j] = max(tmp[j - 1], prices[j] + tmpmax);
                tmpmax = max(tmpmax, dp[j - 1] - prices[j]);
                if (tmp[j] != dp[j])
                {
                    changed = true;
                }
            }
            if (!changed)   break;
            swap(dp, tmp);
        }
        return dp[len - 1];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int k = 0;
		walkString(k, line);
		getline(cin, line);
		vector<int> prices;
		walkString(prices, line);
		cout << toString(Solution().maxProfit(k, prices)) << endl;
	}
	return 0;
}