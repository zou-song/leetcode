#include "lc.h"

class Solution {
public:
    string commonPrefix(const string& str1, const string& str2)
    {
        size_t idx1 = 0, idx2 = 0;
        while (idx1 < str1.size() && idx2 < str2.size())
        {
            if (str1[idx1] == str2[idx2])
            {
                idx1++;
                idx2++;
            }
            else
                break;
        }
        return (idx1 == 0) ? "" : str1.substr(0, idx1);
    }
    string longestCommonPrefix(const vector<string>& strs, int beg, int end)
    {
        if (beg == end) return strs[beg];
        int mid = (beg + end) / 2;
        return commonPrefix(longestCommonPrefix(strs, beg, mid), longestCommonPrefix(strs, mid + 1, end));
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())   return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<string> input;
		walkString(input, line);
		string output = Solution().longestCommonPrefix(input);
		cout << output << endl;
	}
	return 0;
}