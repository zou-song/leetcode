#include "lc.h"

class Solution {
public:
    bool isNumber(string s) {
        int beg = s.find_first_not_of(' ');
        int end = s.find_last_not_of(' ');
        if (beg == string::npos)
            return false;
        bool before_e = true;
        int num_e = 0;
        int num_dot = 0;
        for (int i = beg; i <= end; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else if (s[i] == '-' || s[i] == '+')
            {
                if (i == beg)
                {
                    if (i + 1 > end)
                        return false;
                }
                else if (s[i - 1] == 'e')
                {
                    if (i + 1 > end)
                        return false;
                }
                else
                    return false;
            }
            else if (s[i] == '.')
            {
                if (!before_e)
                    return false;
                if (num_dot > 0)
                    return false;
                if (i == beg && i + 1 > end)
                {
                    return false;
                }
                num_dot++;
            }
            else if (s[i] == 'e')
            {
                if (num_e > 0)
                    return false;
                if (i == beg || i == end)
                    return false;
                before_e = false;
                num_e++;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
	string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}