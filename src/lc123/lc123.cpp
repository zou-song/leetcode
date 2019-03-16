#include "lc.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 1)
            return 0;
        vector<int> vec(len, 0);
        int ret = 0;
        for (int i = 1; i < len; ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                vec[i] = vec[i - 1];
                continue;
            }
            int max_pre = INT_MIN;
            int min_ele = INT_MAX;
            for (int j = 0; j < i; ++j)
            {
                if (vec[j] > max_pre)
                    max_pre = vec[j];
                if (prices[j] < prices[i])
                {
                    if (prices[j] < min_ele)
                        min_ele = prices[j];
                    if (j - 1 < 0)
                    {
                        if (ret < prices[i] - prices[j])
                            ret = prices[i] - prices[j];
                    }
                    else
                    {
                        if (ret < vec[j - 1] + prices[i] - prices[j])
                        {
                            ret = vec[j - 1] + prices[i] - prices[j];
                        }
                    }
                }
            }
            vec[i] = max(max_pre, prices[i] - min_ele);
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