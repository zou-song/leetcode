#include "lc.h"

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> tables(26, 0);
        for (char c : s)
        {
            tables[c - 'a']++;
        }
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (tables[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().firstUniqChar(s)) << endl;
	}
	return 0;
}