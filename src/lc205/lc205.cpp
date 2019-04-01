#include "lc.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set<char> valset;
        unordered_map<char, char> tmpmap;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            auto iter = tmpmap.find(s[i]);
            if (iter != tmpmap.end())
            {
                if (iter->second != t[i])
                    return false;
            }
            else
            {
                if (valset.count(t[i]))
                    return false;
                tmpmap[s[i]] = t[i];
                valset.insert(t[i]);
            }
        }
        return true;
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
		cout << toString(Solution().isIsomorphic(s, t)) << endl;
	}
	return 0;
}