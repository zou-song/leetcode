#include "lc.h"

class Solution {
public:
    bool isPalindrome(const string &str, int idx1, int idx2)
    {
        while (idx1 < idx2)
        {
            if (str[idx1] != str[idx2])
                return false;
            idx1++; idx2--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<vector<string>>> tmp(len + 1);
        if (len <= 0)   return tmp[0];
        tmp[0].push_back({s.substr(0, 1)});
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (isPalindrome(s, j, i))
                {
                    if (j == 0)
                        tmp[i].push_back({s.substr(0, i + 1)});
                    else
                    {
                        for (auto vec : tmp[j - 1])
                        {
                            vec.push_back(s.substr(j, i - j + 1));
                            tmp[i].push_back(vec);
                        }
                    }
                }
            }
        }
        return tmp[len - 1];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().partition(s)) << endl;
	}
	return 0;
}