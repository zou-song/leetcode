#include "lc.h"

class Solution {
public:
    bool canTransform(const string &str1, const string &str2)
    {
        int cnt = 0;
        size_t len1 = str1.size();
        size_t len2 = str2.size();
        if (len1 != len2)
            return false;
        for (size_t i = 0; i < len1; ++i)
        {
            if (str1[i] != str2[i])
                cnt++;
        }
        return cnt == 1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        wordList.push_back(beginWord);
        vector<vector<int>> flagSet(len + 1);
        int retidx = len + 1;
        for (size_t i = 0; i < len + 1; ++i)
        {
            if (wordList[i] == endWord)
                retidx = i;
            for (size_t j = i + 1; j < len + 1; ++j)
            {
                if (canTransform(wordList[i], wordList[j]))
                {
                    flagSet[i].push_back(j);
                    flagSet[j].push_back(i);
                }
            }
        }
        vector<vector<vector<string>>> paths(len + 2);
        paths[len].push_back({beginWord});
        unordered_set<int> nodeSet;
        nodeSet.insert(len);
        unordered_set<int> newSet;
        newSet.insert(len);       
        while (!newSet.empty())
        {
            unordered_set<int> tmp;
            for (int idx : newSet)
            {
                auto &flagVec = flagSet[idx];
                for (int j : flagVec)
                {
                    if(nodeSet.count(j) == 0)
                    {
                        tmp.insert(j);
                        for (auto vec : paths[idx])
                        {
                            vec.push_back(wordList[j]);
                            paths[j].push_back(vec);
                        }
                    }
                }
            }
            nodeSet.insert(tmp.begin(), tmp.end());
            newSet = move(tmp);
        }
        return paths[retidx];
    }
};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        string beginWord;
        walkString(beginWord, line);
        getline(cin, line);
        string endWord;
        walkString(endWord, line);
        getline(cin, line);
        vector<string> wordList;
        walkString(wordList, line);
        cout << toString(Solution().findLadders(beginWord, endWord, wordList)) << endl;
    }
    return 0;
}