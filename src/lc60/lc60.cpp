#include "lc.h"

class Solution {
public:
    string getPermutation(const string& str, int k)
    {
        if (k == 1)
            return str;
        int len = str.size();
        int idx = len - 1;
        int tp = 1;
        for (int i = 1; i <= len && k > (tp * i); ++i)
        {
            idx--;
            tp = tp * i;
        }
        int i = idx;
        for ( ; i < len && k > tp; ++i)
        {
            k -= tp;
        }
        return str.substr(0, idx) + str[i] + getPermutation(str.substr(idx, i - idx) + str.substr(i + 1), k);
    }
    
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; ++i)
            str += to_string(i);
        return getPermutation(str, k);
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
