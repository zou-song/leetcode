#include "lc.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_min = INT_MAX;
        int len = prices.size();
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            if (pre_min > prices[i])
                pre_min = prices[i];
            else if (ret < prices[i] - pre_min)
                ret = prices[i] - pre_min;
        }
        return ret;
    }
};

int main()
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