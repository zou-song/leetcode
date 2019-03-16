#include "lc.h"

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto c : s)
        {
            if (isalnum(c))
                str.push_back(tolower(c));
        }
        int len = str.size();
        int idx1 = 0, idx2 = len - 1;
        while (idx1 < idx2)
        {
            if (str[idx1++] != str[idx2--])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().isPalindrome(s)) << endl;
	}
	return 0;
}