#include "lc.h"

class Solution {
public:
    bool isMatch(const string& s, int idx1, const string &p, int idx2)
    {
        int len1 = s.size();
        int len2 = p.size();
        if (idx2 >= len2 && idx1 < len1)   
            return false;
        if(idx2 >= len2 && idx1 >= len1)
            return true;
        if (idx1 >= len1)
        {
            if (p[idx2] == '*')
                return isMatch(s, idx1, p, idx2 + 1);
            if (idx2 + 2 > len2)
                return false;
            if (p[idx2 + 1] == '*')
                return isMatch(s, idx1, p, idx2 + 2);
            return false;
        }
        if (p[idx2] == '.')
        {
            if (idx2 + 1 >= len2 || p[idx2 + 1] != '*')
                return isMatch(s, idx1 + 1, p, idx2 + 1);
            return isMatch(s, idx1, p, idx2 + 2) || isMatch(s, idx1 + 1, p, idx2);
        }
        else if (p[idx2] == '*')
        {
            if (idx2 == 0 || p[idx2 - 1] != s[idx1])
                return isMatch(s, idx1, p, idx2 + 1);
            return isMatch(s, idx1, p, idx2 + 1) || isMatch(s, idx1 + 1, p, idx2);
        }
        if (idx2 + 1 >= len2 || p[idx2 + 1] != '*')
        {
            if (s[idx1] == p[idx2])
                return isMatch(s, idx1 + 1, p, idx2 + 1);
            return false;
        }
        if (s[idx1] != p[idx2])
            return isMatch(s, idx1, p, idx2 + 2);
        return isMatch(s, idx1, p, idx2 + 2) || isMatch(s, idx1 + 1, p, idx2 + 1);
    }
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}