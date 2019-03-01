#include "lc.h"

class Solution {
public:
    void getNext(const string& str, vector<int> &next)
    {
        if (str.empty())
            return;
        size_t len = str.size();
        next.resize(len);
        next[0] = -1;   //-1 means haystack and needle should both forward a step
        for (size_t i = 1; i < len; ++i)
        {
            int k = next[i - 1];
            while (k >= 0 && str[k] != str[i - 1])
            {
                k = next[k];
            }
            next[i] = k + 1;
        }
    }
    int strStr(string haystack, string needle) {
        //kmp
        //return haystack.find(needle)
        if(needle.empty())
            return 0;
        vector<int> next;
        getNext(needle, next);
        int hay_len = haystack.size();
        int ndl_len = needle.size();
        int i = 0, j = 0;
        while (i < hay_len && j < ndl_len)
        {
            if (j < 0)
            {
                ++i;
                j = 0;
            }
            else if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        if (j < ndl_len)
            return -1;
        return i - ndl_len;
    }
};

int main(int argc, char* argv[])
{
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
