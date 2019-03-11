#include "lc.h"

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        if (len <= 0)   return 0;
        int idx1 = 0;
        while (idx1 < len && str[idx1] == ' ')
            idx1++;
        if (idx1 >= len)    return 0;
        if (str[idx1] != '-' && str[idx1] != '+' && !isdigit(str[idx1]))
            return 0;
        bool neg = false;
        if (str[idx1] == '-')
        {
            neg = true;
            idx1++;
        }
        else if (str[idx1] == '+')
        {
            idx1++;
        }
        if (idx1 >= len || !isdigit(str[idx1])) return 0;
        int idx2 = idx1;
        while (idx2 < len && isdigit(str[idx2]))
            idx2++;
        long long num = 0;
        for (int i = idx1; i < idx2; ++i)
        {
            if (neg)
            {
                int bound = INT_MIN / 10;
                if (bound + num > 0)
                    return INT_MIN;
                else if (bound + num == 0)
                {
                    if (INT_MIN -bound * 10 + (str[i] - '0') > 0)
                        return INT_MIN;
                }
            }
            else
            {
                int bound = INT_MAX / 10;
                if (bound - num < 0)
                    return INT_MAX;
                else if (bound - num == 0)
                {
                    if (INT_MAX - bound * 10 - (str[i] - '0') < 0)
                        return INT_MAX;
                }
            }
            num = num * 10 + (str[i] - '0');
        }
        if (neg)
            num = -num;
        return static_cast<int>(num);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}