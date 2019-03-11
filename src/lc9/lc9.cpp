#include "lc.h"

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.size();
        int idx1 = 0, idx2 = len - 1;
        while (idx1 < idx2)
        {
            if (s[idx1] != s[idx2])
                return false;
            idx1++; idx2--;
        }
        return true;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}