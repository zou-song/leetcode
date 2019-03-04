#include "lc.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end_idx = s.find_last_not_of(' ');
        if (end_idx == string::npos)
            return 0;
        int idx = end_idx;
        while (idx >= 0 && s[idx] != ' ')
            idx--;
        return end_idx - idx;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLastWord(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}