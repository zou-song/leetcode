#include "lc.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        list<int> dp;
        int slen = s.size();
        int plen = p.size();
        dp.push_back(-1);
        for (int i = 0; i < plen; ++i)
        {
            list<int> tmp;
            if (p[i] == '*')
            {
                int idx = dp.front();
                for (int j = idx; j < slen; ++j)
                    tmp.push_back(j);
            }
            else if (p[i] == '?')
            {
                for (int idx : dp)
                    tmp.push_back(idx + 1);
            }
            else
            {
                for (int idx : dp)
                {
                    if (idx + 1 < slen && s[idx + 1] == p[i])
                        tmp.push_back(idx + 1);
                }
            }
            if (tmp.empty())    return false;
            swap(tmp, dp);
        }
        auto iter = find_if(dp.begin(), dp.end(), [slen](int idx){
            return idx == slen - 1;
        });
        return iter != dp.end();
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
		string p;
		walkString(p, line);
		cout << toString(Solution().isMatch(s, p)) << endl;
	}
	return 0;
}