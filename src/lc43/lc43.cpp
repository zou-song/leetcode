#include "lc.h"

class Solution {
public:    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size();
        int len2 = num2.size();
        string ret(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; --i)
        {
            int pre_add = 0;
            for (int j = len2 - 1; j >= 0; --j)
            {
                int n = ret[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + pre_add;
                pre_add = n / 10;
                ret[i + j + 1] = (n % 10) + '0';
            }
            ret[i] += pre_add;
        }
        size_t pos = ret.find_first_not_of('0');
        if (pos != string::npos)
            return ret.substr(pos);
        return "0";
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}