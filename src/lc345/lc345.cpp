#include "lc.h"

class Solution {
public:
    bool isVowel(const char& c) const
    {
        switch (c)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int len = s.size();
        int idx1 = 0, idx2 = len - 1;
        while (idx1 < idx2)
        {
            while (idx1 < idx2 && !isVowel(s[idx1]))
            {
                idx1++;
            }
            while (idx1 < idx2 && !isVowel(s[idx2]))
            {
                idx2--;
            }
            if (idx2 > idx1)
            {
                swap(s[idx1++], s[idx2--]);
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().reverseVowels(s)) << endl;
	}
	return 0;
}