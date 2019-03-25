#include "lc.h"

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string ret;
        int idx = len - 1;
        while (idx >= 0)
        {
            int idx1 = idx;
            while (idx1 >= 0 && s[idx1] == ' ')
                idx1--;
            if (idx1 < 0)
                break;
            int idx2 = idx1;
            while (idx2 >= 0 && s[idx2] != ' ')
                idx2--;
            string word = s.substr(idx2 + 1, idx1 - idx2);
            if (ret.empty())
                ret = word;
            else
                ret = ret + " " + word;
            idx = idx2;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().reverseWords(s)) << endl;
	}
	return 0;
}