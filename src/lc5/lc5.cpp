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
    string longestPalindrome(string s) {
        if (s.empty())  return s;
        int len = s.size();
        vector<int> dp(len);
        dp[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            int begIdx = i - 1 - dp[i - 1];
            if (begIdx >= 0 && s[begIdx] == s[i])
                dp[i] = dp[i - 1] + 2;
            else
            {
                if (begIdx < 0) begIdx = 0;
                for (int j = begIdx; j <= i; ++j)
                {
                    if (s[j] == s[i] && isPalindrome(s, j, i))
                        dp[i] = i - j + 1;
                }
            }
        }
        int maxLen = 0, maxIdx = 0;
        for (int i = 0; i < len; ++i)
        {
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        return s.substr(maxIdx - maxLen + 1, maxLen);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().longestPalindrome(s)) << endl;
	}
	return 0;
}