#include "lc.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        if (len <= 0)   return "";
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        tmp = s + "#" + tmp;
        vector<int> next(2 * len + 1, -1);
        for (int i = 1; i < 2 * len + 1; ++i)
        {
            int k = next[i - 1];
            while (k >= 0 && tmp[i - 1] != tmp[k])
            {
                k = next[k];
            }
            next[i] = k + 1;
        }
        int idx = 0;
        for (int i = len + 1; i < 2 * len + 1; ++i)
        {
            if (next[i] > idx)
            {
                idx = next[i];
            }
        }
        tmp.clear();
        int i = len - 1;
        while (i >= idx)
        {
            tmp += s[i--];
        }
        tmp += s;
        return s;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().shortestPalindrome(s)) << endl;
	}
	return 0;
}