#include "lc.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty())    return {};
        typedef unordered_map<string, int> DPELEM;
        int len = num.size();
        vector<DPELEM> dp(len);
        dp[0][num.substr(0, 1)] = num[0] - '0';
        for (int i = 1; i < len; ++i)
        {
            string s = num.substr(0, i + 1);
            if (s[0] != '0')
                dp[i][s] = stoi(s);
            for (int j = 1; j <= i; ++j)
            {
                string str = num.substr(j, i - j + 1);
                if (str.size() > 1 && str[0] == '0')
                    continue;
                int rnum = stoi(str);
                auto &elem = dp[j - 1];
                for (auto &pr : elem)
                {
                    string key = pr.first + "+" + str;
                    int val = pr.second + rnum;
                    dp[i][key] = val;
                    key = pr.first + "-" + str;
                    val = pr.second - rnum;
                    dp[i][key] = val;
                    key = pr.first + "*" + str;
                    int k = pr.first.size() - 1;
                    int mul = 1;
                    char flag = '*';
                    while (k >= 0)
                    {
                        if (isdigit(pr.first[k]))
                        {
                            mul *= k;
                            k--;
                        }
                        else if (pr.first[k] == '*')
                        {
                            k--;
                        }
                        else
                        {
                            flag = pr.first[k];
                            break;
                        }
                    }
                    if (flag == '+')
                    {
                        val = pr.second - mul + mul * rnum;
                    }
                    else if (flag == '-')
                    {
                        val = pr.second + mul - mul * rnum;
                    }
                    else
                    {
                        val = mul * rnum;
                    }
                    dp[i][key] = val;
                }
            }   
        }
        vector<string> ret;
        DPELEM &elem = dp[len - 1];
        for_each(elem.begin(), elem.end(), [&ret, target](const pair<string, int>& pr){
            if (pr.second == target)
                ret.push_back(pr.first);
        });
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