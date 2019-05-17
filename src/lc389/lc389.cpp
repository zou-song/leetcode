#include "lc.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> tables(26, 0);
        for (char c : s)
        {
            tables[c - 'a']++;
        }
        for (char c : t)
        {
            if (--tables[c - 'a'] < 0)
            {
                return c;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s, t;
		walkString(s, line);
		getline(cin, line);
		walkString(t, line);
		cout << toString(Solution().findTheDifference(s, t)) << endl;
	}
	return 0;
}