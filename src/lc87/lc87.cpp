#include "lc.h"

class Solution {
public:
    bool isScramble(const string& s1, int b1, int e1, const string& s2, int b2, int e2)
    {
        if (e1 - b1 != e2 - b2)
            return false;
        else if (e1 < b1)    return true;
        else if (s1.substr(b1, e1 - b1 + 1) == s2.substr(b2, e2 - b2 + 1))
            return true;
        for (int i = b2; i <= e2; ++i)
        {
            if (s2[i] == s1[b1])
            {
                int len = i - b2 + 1;
                bool ret = isScramble(s1, b1 + 1, b1 + len - 1, s2, b2, i - 1) &&
                    isScramble(s1, b1 + len, e1, s2, i + 1, e2);
                if (ret)
                    return ret;
                else    continue;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        return isScramble(s1, 0, len1 - 1, s2, 0, len2 - 1);
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