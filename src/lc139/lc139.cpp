#include "lc.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto &str : wordDict)
        {
            wordSet.insert(str);
        }
        int len = s.size();
        set<int> tmpSet;
        int idx = 0;
        while (idx < len)
        {
            if (wordSet.count(s.substr(0, idx + 1)))
            {
                tmpSet.insert(idx);
                idx++;
                continue;
            }
            for (int i : tmpSet)
            {
                if (wordSet.count(s.substr(i + 1, idx - i)))
                {
                    tmpSet.insert(idx);
                    break;
                }
            }
            idx++;
        }
        auto iter = tmpSet.rbegin();
        if (iter == tmpSet.rend())
            return false;
        return *iter == len - 1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		getline(cin, line);
		vector<string> wordDict;
		walkString(wordDict, line);
		cout << toString(Solution().wordBreak(s, wordDict)) << endl;
	}
	return 0;
}