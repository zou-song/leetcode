#include "lc.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hmap;
        for (char c : s)
            hmap[c]++;
        for (char c : t)
        {
            auto iter = hmap.find(c);
            if (iter == hmap.end())
                return false;
            else if (iter->second - 1 == 0)
                hmap.erase(iter);
            else
                iter->second--;
        }
        return hmap.empty();
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		string t;
		getline(cin, line);
		walkString(t, line);
		cout << toString(Solution().isAnagram(s, t)) << endl;
	}
	return 0;
}