#include "lc.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        int len = s.size();
        vector<int> tmp(len);
        tmp[0] = 0;
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == '(')
                tmp[i] = 0;
            else
            {
                int j = i - 1- tmp[i - 1];
                if (j >= 0 && s[j] == '(')
                {
                    if (j - 1 < 0)
                        tmp[i] = 2 + tmp[i - 1];
                    else
                        tmp[i] = 2 + tmp[i - 1] + tmp[j - 1];
                }
                else
                    tmp[i] = 0;
            }
        }
        return *max_element(tmp.begin(), tmp.end());
    }
};

int main(int argc, char *argv[])
{
	string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
	return 0;
}
