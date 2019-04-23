#include "lc.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> thmap;
        for (char c : t)
        {
            thmap[c]++;
        }
        int tmapsz = thmap.size();
        int idx = 0, len = INT_MAX;
        int beg = 0, end = 0;
        int slen = s.size();
        unordered_map<char, int> wdhmap;
        int cnt = 0;
        while (end < slen)
        {
            auto iter = thmap.find(s[end]);
            if (iter != thmap.end())
            {
                if (++wdhmap[s[end]] == iter->second)
                    cnt++;
                if (cnt >= tmapsz)
                {
                    if (end - beg + 1 < len)
                    {
                        len = end - beg + 1;
                        idx = beg;
                    }
                    while (beg <= end && cnt >= tmapsz)
                    {
                        auto iter2 = thmap.find(s[beg]);
                        if (iter2 != thmap.end())
                        {
                            if (--wdhmap[s[beg++]] < iter2->second)
                            {
                                cnt--;
                            }
                        }
                        else
                            beg++;
						if (cnt >= tmapsz && end - beg + 1 < len)
						{
							len = end - beg + 1;
							idx = beg;
						}
                    }
                }
            }
            end++;
        }
        if (len != INT_MAX)
            return s.substr(idx, len);
        return "";
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
		cout << toString(Solution().minWindow(s, t)) << endl;
	}
	return 0;
}
