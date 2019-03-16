#include "lc.h"

class Solution {
public:
    //dp
    int maxProfit_dp(vector<int>& prices) {
        int len = prices.size();
        if (len < 1)
            return 0;
        vector<int> vec(len, 0);
        auto iter1 = vec.begin();
        for (int i = 1; i < len; ++i)
        {
            if (prices[i] <= prices[i - 1])
            {
                vec[i] = vec[i - 1];
                continue;
            }
            int max_pre = *max_element(iter1, iter1 + i);
            for (int j = 0; j < i; ++j)
            {
                if (prices[j] < prices[i])
                {
                    int tmp = 0;
                    if (j - 1 < 0)
                        tmp = prices[i] - prices[j];
                    else
                        tmp = prices[i] - prices[j] + vec[j - 1];
                    if (tmp > max_pre)
                        max_pre = tmp;
                }
            }
            vec[i] = max_pre;
        }
        return vec[len - 1];
    }
    
    int maxProfit(vector<int>& prices)
    {
        int ret = 0;
        int len = prices.size();
        for (int i = 1; i < len; ++i)
        {
            if (prices[i] > prices[i - 1])
                ret += (prices[i] - prices[i - 1]);
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