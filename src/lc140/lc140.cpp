#include "lc.h"

class Solution {
    struct DictNode
    {
        bool _self;
        vector<DictNode*> _children;
        
        DictNode() : _self(false) {}
    };
    DictNode _head;
    static const int DICTSIZE = 26;
public:
    void wordBreak(const string& s, int idx, const string& str, vector<string>& ret)
    {
        int len = s.size();
        if (idx >= len)
        {
            ret.push_back(str);
            return;
        }
        DictNode* p = &_head;
        for (int i = idx; i < len; ++i)
        {
            int j = s[i] - 'a';
            if (p->_children.empty() || !p->_children[j])
            {
                return;
            }
            p = p->_children[j];
            if (p->_self)
            {
                string tmp = str;
                if (tmp.empty())
                {
                    tmp = s.substr(idx, i - idx + 1);
                }
                else
                {
                    tmp = tmp + " " + s.substr(idx, i - idx + 1);
                }
                wordBreak(s, i + 1, tmp, ret);
            }
        }
    }
    bool contain(const string& s)
    {
        DictNode *p = &_head;
        for (char c : s)
        {
            int idx = c - 'a';
            if (p->_children.empty() || !p->_children[idx])
                return false;
            p = p->_children[idx];
        }
        return p && p->_self;
    }
    bool canSolve(const string& s)
    {
        int len = s.size();
        vector<bool> dp(len, false);
        for (int i = 0; i < len; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (j == 0)
                {
                    dp[i] = contain(s.substr(j, i - j + 1));
                }
                else
                {
                    dp[i] = contain(s.substr(j, i - j + 1)) && dp[j - 1];
                }
                if (dp[i])
                {
                    break;
                }
            }
        }
        return !dp.empty() && dp[len - 1];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string& str : wordDict)
        {
            DictNode *p = &_head;
            for (char c : str)
            {
                int idx = c - 'a';
                if (p->_children.empty())
                {
                    p->_children.resize(DICTSIZE);
                    fill(p->_children.begin(), p->_children.end(), nullptr);
                }
                if (!p->_children[idx])
                {
                    p->_children[idx] = new DictNode;
                }
                p = p->_children[idx];
            }
            p->_self = true;
        }
        vector<string> ret;
        if (!canSolve(s))   return ret;
        list<pair<int, string>> dp;
        dp.emplace_back(-1, "");
        int idx = 0;
        int len = s.size();   
        while (!dp.empty())
        {
            pair<int, string> &pr = dp.front();
            if (pr.first >= len - 1)
            {
                ret.push_back(pr.second);
            }
            else
            {
                DictNode *p = &_head;
                for (int i = pr.first + 1; i < len; ++i)
                {
                    int idx = s[i] - 'a';
                    if (p->_children.empty() || !p->_children[idx])
                    {
                        break;
                    }
                    p = p->_children[idx];
                    if (p->_self)
                    {
                        string str = pr.second;
                        if (str.empty())
                        {
                            str = s.substr(pr.first + 1, i - pr.first);
                        }
                        else
                        {
                            str = str + " " + s.substr(pr.first + 1, i - pr.first);
                        }
                        dp.emplace_back(i, str);
                    }
                }
            }
            dp.pop_front();
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
		vector<string> wordDict;
		getline(cin, line);
		walkString(wordDict, line);
		cout << toString(Solution().wordBreak(s, wordDict)) << endl;
	}
	return 0;
}