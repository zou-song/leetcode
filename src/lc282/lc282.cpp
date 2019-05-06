#include "lc.h"

class Solution {
public:
    void func(const string& num, int idx, int target, int cur, int mul, char oper, const string& str, vector<string>& ret)
    {
        int len = num.size();
        if (idx >= len)
        {
            if (cur == target)
            {
                ret.push_back(str);
            }
            return;
        }
        if (idx == 0)
        {
            if (num[0] == '0')
            {
                func(num, 1, target, 0, 0, '+', "0", ret);
            }
            else
            {
                for (int i = 0; i < len - 1; ++i)
                {
                    string tmp = num.substr(0, i + 1);
                    long long nll = stoi(tmp);
                    if (nll > INT_MAX)
                    {
                        break;
                    }
                    func(num, i + 1, target, nll, nll, '+', tmp, ret);
                }
            }
            return;
        }
        if (num[idx] == 0)
        {
            string tmp = str + "+" + num[idx];
            func(num, idx + 1, target, cur, 0, '+', tmp, ret);
            tmp = str + "-" + num[idx];
            func(num, idx + 1, target, cur, 0, '-', tmp, ret);
            tmp = str + "*" + num[idx];
            switch (oper)
            {
                case '+':
                    cur = cur - mul + mul * 0;
                    mul = 0;
                    break;
                case '-':
                    cur = cur + mul - mul * 0;
                    mul = 0;
                    break;
            }
            func(num, idx + 1, target, cur, mul, oper, tmp, ret);
            return;
        }
        for (int i = idx; i < len; ++i)
        {
            string s = num.substr(idx, i - idx + 1);
            long long nll = stoll(s);
            if (nll > INT_MAX)
            {
                break;
            }
            string tmp = str + "+" + s;
            long long a = cur + nll;
            if (a <= INT_MAX)
            {
                func(num, i + 1, target, a, nll, '+', tmp, ret);
            }
            tmp = str + "-" + s;
            a = cur - nll;
            if (a >= INT_MIN)
            {
                func(num, i + 1, target, a, nll, '-', tmp, ret);
            }
            tmp = str + "*" + s;
            switch (oper)
            {
                case '+':
                    a = cur - mul + mul * nll;
                case '-':
                    a = cur + mul - mul * nll;
            }
            if (a >= INT_MIN && a <= INT_MAX && mul * nll <= INT_MAX)
            {
                func(num, i + 1, target, a, mul * nll, oper, tmp, ret);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        func(num, 0, target, 0, 0, '+', "", ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string num;
		walkString(num, line);
		getline(cin, line);
		int target = 0;
		walkString(target, line);
		cout << toString(Solution().addOperators(num, target)) << endl;
	}
	return 0;
}