#include "lc.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        int idx = 0;
        int pre_add = 0;
        string ret;
        while (idx < len1 && idx < len2)
        {
            int b1 = a[len1 - idx - 1] - '0';
            int b2 = b[len2 - idx - 1] - '0';
            pre_add = (pre_add + b1 + b2);
            ret = to_string(pre_add & 1) + ret;
            pre_add = pre_add >> 1;
            idx++;
        }
        while (idx < len1)
        {
            int b1 = a[len1 - idx - 1] - '0';
            pre_add = (pre_add + b1);
            ret = to_string(pre_add & 1) + ret;
            pre_add = pre_add >> 1;
            idx++;
        }
        while (idx < len2)
        {
            int b2 = b[len2 - idx - 1] - '0';
            pre_add = pre_add + b2;
            ret = to_string(pre_add & 1) + ret;
            pre_add = pre_add >> 1;
            idx++;
        }
        if (pre_add)
            ret = '1' + ret;
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}