#include "lc.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())  return 0;
        if (s[0] == '0')    return 0;
        int len = s.size();
        vector<int> tmp(len, 0);
        tmp[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                if (i - 2 <= 0)
                    tmp[i] = 1;
                else
                    tmp[i] = tmp[i - 2];
            }
            else
            {
                if (s[i - 1] == '0' || s[i - 1] > '2')
                    tmp[i] = tmp[i - 1];
                else if (s[i - 1] == '2')
                {
                    if (s[i] > '6')
                        tmp[i] = tmp[i - 1];
                    else
                    {
                        if (i - 2 <= 0)
                            tmp[i] = tmp[i - 1] + 1;
                        else
                            tmp[i] = tmp[i - 1] + tmp[i - 2];
                    }
                }
                else
                {
                    if (i - 2 <= 0)
                        tmp[i] = tmp[i - 1] + 1;
                    else
                        tmp[i] = tmp[i - 1] + tmp[i - 2];
                }
            }
        }
        return tmp[len - 1];
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
