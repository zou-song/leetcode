#include "lc.h"

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int ret = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            int n = s[i] - 'A' + 1;
            ret = n * pow(26, len - i - 1) + ret;
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
		cout << toString(Solution().titleToNumber(s)) << endl;
	}
	return 0;
}