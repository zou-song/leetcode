#include "lc.h"

class Solution {
public:
    void func(const string &str, int idx, vector<string>& ret, string s, int num)
    {
        if (num > 4)
            return;
        if ((size_t)idx >= str.size())
        {
            if (num != 4)
                return;
            else
            {
                ret.push_back(s);
                return;
            }
        }
        if (str[idx] == '0')
        {
            if (s.empty())
                s = "0";
            else
                s = s + "." + "0";
            func(str, idx + 1, ret, s, num + 1);
        }
        else
        {
            int len = str.size();
            if (s.empty())
                func(str, idx + 1, ret, str.substr(idx, 1), num + 1);
            else
                func(str, idx + 1, ret, s + "." + str[idx], num + 1);
            if (idx + 1 < len)
            {
                if (s.empty())
                    func(str, idx + 2, ret, str.substr(idx, 2), num + 1);
                else
                    func(str, idx + 2, ret, s + "." + str.substr(idx, 2), num + 1);
            }
            if (idx + 2 < len)
            {
                int tmp = stoi(str.substr(idx, 3));
                if (tmp < 256)
                {
                    if (s.empty())
                        func(str, idx + 3, ret, str.substr(idx, 3), num + 1);
                    else
                        func(str, idx + 3, ret, s + "." + str.substr(idx, 3), num + 1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if (s.empty())  return ret;
        func(s, 0, ret, "", 0);
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string input;
		walkString(input, line);
		auto output = Solution().restoreIpAddresses(input);
		cout << toString(output) << endl;
	}
	return 0;
}