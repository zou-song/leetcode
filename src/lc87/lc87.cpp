#include "lc.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 != len2)   return false;
        vector<vector<vector<bool>>> dp(len1);
        for_each(dp.begin(), dp.end(), [len1](vector<vector<bool>>& vec){
            vec.resize(len1);
            for_each(vec.begin(), vec.end(), [len1](vector<bool>& v){
                v.resize(len1 + 1);
            });
        });
        for (int i = 0; i < len1; ++i)
        {
            for (int j = 0; j < len1; ++j)
            {
                fill(dp[i][j].begin(), dp[i][j].end(), false);
                dp[i][j][0] = true;
                if (s1[i] == s2[j])
                {
                    dp[i][j][1] = true;
                }
            }
        }
        for (int len = 2; len <= len1; ++len)
        {
            for (int i = 0; i < len1; ++i)
            {
                for (int j = 0; j < len1; ++j)
                {
                    for (int k = 1; k < len; ++k)
                    {
                        if (j + k >= len1)  break;
                        if (i + k >= len1)  break;
                        if (j + len - k >= len1)    continue;
                        if (dp[i][j][k] && dp[i + k][j + k][len - k])
                        {
                            dp[i][j][len] = true;
                            break;
                        }
                        else if (dp[i][j + len - k][k] && dp[i + k][j][len - k])
                        {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][len1];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s1, s2;
		walkString(s1, line);
		getline(cin, line);
		walkString(s2, line);
		cout << toString(Solution().isScramble(s1, s2)) << endl;
	}
	return 0;
}