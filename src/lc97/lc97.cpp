#include "lc.h"

class Solution {
public:
    bool isInterleave(const string &str1, size_t idx1, const string& str2, size_t idx2, const string& str3)
    {
        size_t len1 = str1.size();
        size_t len2 = str2.size();
        if (idx1 >= len1)
        {
            if(idx2 >= len2)
                return true;
            else if (str2.substr(idx2) == str3.substr(idx1 + idx2))
                return true;
            else
                return false;
        }
        if (idx2 >= len2)
        {
            if (idx1 >= len1)
                return true;
            else if (str1.substr(idx1) == str3.substr(idx1 + idx2))
                return true;
            else
                return false;
        }
        if (str1[idx1] == str3[idx1 + idx2])
        {
            if (str2[idx2] == str3[idx1 + idx2])
                return isInterleave(str1, idx1 + 1, str2, idx2, str3) || isInterleave(str1, idx1, str2, idx2 + 1, str3);
            else
                return isInterleave(str1, idx1 + 1, str2, idx2, str3);
        }
        else if (str2[idx2] == str3[idx1 + idx2])
        {
            return isInterleave(str1, idx1, str2, idx2 + 1, str3);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        //method 1
        //return isInterleave(s1, 0, s2, 0, s3);
        //method 2
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<bool>> tmp(len1 + 1);
        for_each(tmp.begin(), tmp.end(), [len2](vector<bool> &vec){
            vec.resize(len2 + 1);
            fill(vec.begin(), vec.end(), false);
        });
        tmp[0][0] = true;
        for (int i = 0; i <= len1; ++i)
        {
            for (int j = 0; j <= len2; ++j)
            {
                if (i == 0 && j == 0)   continue;
                bool b1 = false, b2 = false;
                if (i - 1 >= 0)
                {
                    tmp[i][j] = tmp[i][j] || ((s1[i - 1] == s3[i + j - 1]) && tmp[i - 1][j]);
                }
                if (j - 1 >= 0)
                {
                    tmp[i][j] = tmp[i][j] || ((s2[j - 1] == s3[i + j - 1]) && tmp[i][j - 1]);
                }
            }
        }
        return tmp[len1][len2];
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);
        
        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}