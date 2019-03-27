#include "lc.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int base = 4;
        unordered_map<char, int> tmpMap;
        tmpMap['A'] = 0;
        tmpMap['C'] = 1;
        tmpMap['G'] = 2;
        tmpMap['T'] = 3;
        int len = s.size();
        if (len < 10)   return {};
        int tmp = 1;
        unsigned long long h = 0;
        for (int i = 9; i >= 0; --i)
        {
            int n = tmpMap[s[i]];
            h = h + n * tmp;
            tmp = tmp * base;
        }
        unordered_map<unsigned long long, int> cntMap;
        cntMap[h] = 1;
        vector<string> ret;
        tmp = tmp / base;
        for (int i = 10; i < len; ++i)
        {
            h = h % tmp;
            h = h * base + tmpMap[s[i]];
            if (++cntMap[h] == 2)
                ret.push_back(s.substr(i - 9, 10));
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
		cout << toString(Solution().findRepeatedDnaSequences(s)) << endl;
	}
	return 0;
}