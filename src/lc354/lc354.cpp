#include "lc.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        });
        int len = envelopes.size();
        vector<int> dp(len, 1);
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> envelopes;
		walkString(envelopes, line);
		cout << toString(Solution().maxEnvelopes(envelopes)) << endl;
	}
	return 0;
}