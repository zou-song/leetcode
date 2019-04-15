#include "lc.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> fwd_map;
        unordered_map<string, char> bwd_map;
        int idx = 0;
        int str_len = str.size();
        for (char c : pattern)
        {
            while (idx < str_len && str[idx] == ' ')
                idx++;
            if (idx >= str_len) return false;
            int end_idx = idx + 1;
            while (end_idx < str_len && str[end_idx] != ' ')
                end_idx++;
            idx = end_idx;
            string s = str.substr(idx, end_idx - idx);
            auto fwd_iter = fwd_map.find(c);
            if (fwd_iter != fwd_map.end())
            {
                if (fwd_iter->second != s)
                    return false;
            }
            else
            {
                auto bwd_iter = bwd_map.find(s);
                if (bwd_iter != bwd_map.end())
                    return false;
                fwd_map[c] = s;
                bwd_map[s] = c;
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
		string pattern;
		walkString(pattern, line);
		getline(cin, line);
		string str;
		walkString(str, line);
		cout << toString(Solution().wordPattern(pattern, str)) << endl;
	}
	return 0;
}