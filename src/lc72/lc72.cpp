#include "lc.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1);
        for_each(dp.begin(), dp.end(), [len2](vector<int>& vec){
            vec.resize(len2 + 1);
        });
        dp[0][0] = 0;
        for (int i = 0; i < len1; ++i)
        {
            dp[i + 1][0] = i + 1;
        }
        for (int i = 0; i < len2; ++i)
        {
            dp[0][i + 1] = i + 1;
        }
        for (int i = 0; i < len1; ++i)
        {
            int dpx = i + 1;
            for (int j = 0; j < len2; ++j)
            {
                int dpy = j + 1;
                vector<int> cmps(3);
                cmps[0] = dp[dpx][dpy - 1] + 1;
                cmps[1] = dp[dpx - 1][dpy] + 1;
                cmps[2] = (word1[i] == word2[j]) ? dp[dpx - 1][dpy - 1] : dp[dpx - 1][dpy - 1] + 1;
                dp[dpx][dpy] = *min_element(cmps.begin(), cmps.end());
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string word1;
		walkString(word1, line);
		getline(cin, line);
		string word2;
		walkString(word2, line);
		cout << toString(Solution().minDistance(word1, word2)) << endl;
	}
	return 0;
}