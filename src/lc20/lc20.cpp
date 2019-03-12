#include "lc.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (char c : s)
        {
            switch (c)
            {
                case '(':
                case '[':
                case '{':
                    tmp.push(c);
                    break;
                case ')':
                    if (tmp.empty() || tmp.top() != '(')
                        return false;
                    tmp.pop();
                    break;
                case ']':
                    if (tmp.empty() || tmp.top() != '[')
                        return false;
                    tmp.pop();
                    break;
                case '}':
                    if (tmp.empty() || tmp.top() != '{')
                        return false;
                    tmp.pop();
                    break;
                default:
                    return false;
            }
        }
        if (!tmp.empty())   return false;
        return true;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}