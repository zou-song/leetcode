#include "lc.h"

class Solution {
public:
    bool isPalindrome(const string& str, int idx1, int idx2)
    {
        while (idx1 < idx2)
        {
            if (str[idx1] != str[idx2])
                return false;
            idx1++; idx2--;
        }
        return true;
    }
    int minCut(string s) {
        int len = s.size();
        if (len <= 0)   return 0;
        vector<int> dp(len);
        dp[0] = 0;
        for (int i = 1; i < len; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j <= i; ++j)
            {
                if (isPalindrome(s, j, i))
                {
                    if (j == 0)
                    {
                        dp[i] = 0;
                        break;
                    }
                    else
                    {
                        if (dp[j - 1] + 1 < dp[i])
                            dp[i] = dp[j - 1] + 1;
                    }
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
		string s;
		walkString(s, line);
		cout << toString(Solution().minCut(s)) << endl;
	}
	return 0;
}