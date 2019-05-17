#include "lc.h"

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        int len = s.size();
        int idx = 0;
        int repeated_num = 1;
        while (idx < 0)
        {
            if (isdigit(s[idx]))
            {
                repeated_num = s[idx] - '0';
                idx++;
            }
            else if (s[idx] == '[')
            {
                stk.emplace("", repeated_num);
                idx++;
            }
            else if (s[idx] == ']')
            {
                string tmp;
                int num = stk.top().second;
                while (num > 0)
                {
                    tmp += stk.top().first;
                    num--;
                }
                stk.pop();
                if (stk.empty())
                {
                    stk.emplace(tmp, 1);
                }
                else
                {
                    stk.top().first += tmp;
                }
                repeated_num = 1;
                idx++;
            }
            else
            {
                if (stk.empty())
                {
                    stk.emplace(s.substr(idx, 1), 1);
                }
                else
                {
                    stk.top().first += s[idx];
                }
                idx++;
            }
        }
        if (stk.empty())
        {
            return "";
        }
        return stk.top().first;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().decodeString(s)) << endl;
	}
	return 0;
}