#include "lc.h"

class Solution {
public:
    bool canTransform(const string &str1, const string& str2)
    {
        int cnt = 0;
        if (str1.size() != str2.size())
            return false;
        for (size_t i = 0; i < str1.size(); ++i)
        {
            if (str1[i] != str2[i])
                cnt++;
        }
        return cnt == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        auto iter = find(wordList.begin(), wordList.end(), endWord);
        if (iter == wordList.end())
            return 0;
        vector<vector<bool>> tmp(len + 1);
        for_each(tmp.begin(), tmp.end(), [len](vector<bool> &vec){
            vec.resize(len + 1);
        });
        wordList.push_back(beginWord);
        for (int i = 0; i < len + 1; ++i)
        {
            tmp[i][i] = false;
            for (int j = i + 1; j < len + 1; ++j)
            {
                if(canTransform(wordList[i], wordList[j]))
                    tmp[i][j] = tmp[j][i] = true;
                else
                    tmp[i][j] = tmp[j][i] = false;
            }
        }
        vector<bool> flag(len + 1, false);
        vector<int> step(len + 1, 0);
        flag[len] = true;
        step[len] = 1;
        queue<int> que;
        que.push(len);
        while (!que.empty())
        {
            queue<int> tmpque;
            while (!que.empty())
            {
                int idx = que.front();
                que.pop();
                for (int i = 0; i < len; ++i)
                {
                    if (tmp[idx][i] && !flag[i])
                    {
                        if (wordList[i] == endWord)
                            return step[idx] + 1;
                        flag[i] = true;
                        tmpque.push(i);
                        step[i] = step[idx] + 1;
                    }
                }
            }
            swap(que, tmpque);
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string beginWord, endWord;
		walkString(beginWord, line);
		getline(cin, line);
		walkString(endWord, line);
		vector<string> wordList;
		getline(cin, line);
		walkString(wordList, line);
		cout << toString(Solution().ladderLength(beginWord, endWord, wordList)) << endl;
	}
	return 0;
}
