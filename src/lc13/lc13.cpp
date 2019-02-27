#include "lc.h"

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        size_t len = s.size();
        int ret = 0;
        for (size_t i = 0; i < len; )
        {
            if (i < len - 1)
            {
                int ln = roman_map[s[i]];
                int rn = roman_map[s[i + 1]];
                if (ln < rn)
                {
                    ret += (rn - ln);
                    i += 2;
                }
                else
                {
                    ret += ln;
                    i++;
                }
            }
            else
            {
                ret += roman_map[s[i]];
                i++;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}