#include "lc.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for (char c : magazine)
        {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            if (--cnt[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string ransomNote, magazine;
	while (getline(cin, line))
	{
		walkString(ransomNote, line);
		getline(cin, line);
		walkString(magazine, line);
		cout << toString(Solution().canConstruct(ransomNote, magazine)) << endl;
	}
	return 0;
}