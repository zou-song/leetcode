#include "lc.h"

class Solution {
public:
    void numDistinct(const string& s, int idx1, const string& t, int idx2, int& ret)
    {
        int slen = s.size();
        int tlen = t.size();
        if (idx2 >= tlen)
        {
            ret++;
            return;
        }
        else if (idx1 >= slen)
        {
            return;
        }
        for (int i = idx1; i < slen; ++i)
        {
            if (s[i] == t[idx2])
            {
                numDistinct(s, i + 1, t, idx2 + 1, ret);
            }
        }
    }
    int numDistinct1(string s, string t) {
        int ret = 0;
        numDistinct(s, 0, t, 0, ret);
        return ret;
    }
    int numDistinct(string s, string t) {
        int tlen = t.size();
        int slen = s.size();
        vector<vector<int>> dp(slen + 1);
        for_each(dp.begin(), dp.end(), [tlen](vector<int>& vec){
            vec.resize(tlen + 1);
            fill(vec.begin(), vec.end(), 0);
        });
        for (int i = 0; i < slen; ++i)
        {
            dp[i][0] = 1;
            for (int j = 0; j < tlen; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
                }
                else
                {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                }
            }
        }
        return dp[slen][tlen];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s, t;
		walkString(s, line);
		getline(cin, line);
		walkString(t, line);
		cout << toString(numDistinct(s, t)) << endl;
	}
	return 0;
}