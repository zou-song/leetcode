#include "lc.h"

class Solution {
public:
    static vector<string> lettermap;
    void letterCombinations(const string &digits, int idx, vector<string>& ret, string &str)
    {
        int len = digits.size();
        if (idx >= len)
        {
            if (str.empty())    return;
            ret.push_back(str);
            return;
        }
        int n = digits[idx] - '0';
        for (auto letter : lettermap[n])
        {
            str += letter;
            letterCombinations(digits, idx + 1, ret, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string str;
        letterCombinations(digits, 0, ret, str);
        return ret;
    }
};

vector<string> Solution::lettermap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main()
{
	string line;
	while (getline(cin, line))
	{
		string input;
		walkString(input, line);
		auto output = Solution().letterCombinations(input);
		cout << toString(output) << endl;
	}
	return 0;
}
