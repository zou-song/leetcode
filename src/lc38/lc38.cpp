#include "lc.h"

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if (n <= 1)
            return str;
        for (int i = 2; i <= n; ++i)
        {
            int len = str.size();
            string tmp;
            int j = 0, k = 0;
            while (k < len)
            {
                while (k < len && str[k] == str[j])
                {
                    k++;
                }
                int cnt = k - j;
                tmp = tmp + to_string(cnt) + str[j];
                j = k;
            }
            str = tmp;
        }
        return str;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
