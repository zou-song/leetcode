#include "lc.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            if (s[idx1] == t[idx2])
            {
                idx1++;
                idx2++;
            }
            else
            {
                idx2++;
            }
        }
        return !(idx1 < len1);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		getline(cin, line);
		string t;
		walkString(t, line);
		cout << toString(Solution().isSubsequence(s, t)) << endl;
	}
	return 0;
}