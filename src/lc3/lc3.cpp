#include "lc.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())  return 0;
        int len = s.size();
        vector<int> tmp(len);
        tmp[0] = 1;
        int ret = 1;
        for (int i = 1; i < len; ++i)
        {
            int j = i - tmp[i - 1];
            while (s[j] != s[i])
                j++;
            if (j == i)
                tmp[i] = tmp[i - 1] + 1;
            else
                tmp[i] = i - j;
            if (ret < tmp[i])
                ret = tmp[i];
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}