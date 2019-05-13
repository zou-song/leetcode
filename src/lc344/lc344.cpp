#include "lc.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int idx1 = 0, idx2 = len - 1;
        while (idx2 > idx1)
        {
            swap(s[idx1++], s[idx2--]);
        }
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<char> s;
		walkString(s, line);
		Solution().reverseString(s);
		cout << toString(s) << endl;
	}
	return 0;
}