#include "lc.h"

class Solution {
    struct DPKeeper
    {
        bool** _dp;
        int _len;
        
        DPKeeper(int len) : _len(len)
        {
            if (len <= 0)   return;
            _dp = new bool*[len];
            for_each(_dp, _dp + len, [len](bool* &p){
                p = new bool[len];
                fill(p, p + len, false);
            });
        }
        ~DPKeeper()
        {
            for (int i = 0; i < _len; ++i)
            {
                delete[] _dp[i];
            }
            if (_dp)
                delete[] _dp;
        }
        
        bool*& operator[] (size_t idx)
        {
            return _dp[idx];
        }
    };
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
    string longestPalindrome1(string s) {
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
					{
                        dp[i] = i - j + 1;
						break;
					}
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

//dp
    string longestPalindrome(string s) {
        int start = 0;
        int ret_len = 0;
        int len = s.size();
        if (len <= 0)   return "";
        DPKeeper dp(len);
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (i == j)
                    dp[j][i] = true;
                else if (j + 1 == i)
                {
                    if (s[i] == s[j])
                        dp[j][i] = true;
                    else
                        dp[j][i] = false;
                }
                else
                {
                    if (dp[j + 1][i - 1] && s[i] == s[j])
                        dp[j][i] = true;
                    else
                        dp[j][i] = false;
                }
                if (dp[j][i])
                {
                    if (i - j + 1 > ret_len)
                    {
                        ret_len = i - j + 1;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, ret_len);
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
