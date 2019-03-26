#include "lc.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            int i = version1.find_first_of('.', idx1);
            int n1 = 0;
            if (i == string::npos)
            {
                n1 = stoi(version1.substr(idx1));
                idx1 = len1;
            }
            else
            {
                n1 = stoi(version1.substr(idx1, i - idx1));
                idx1 = i + 1;
            }
            int j = version2.find_first_of('.', idx2);
            int n2 = 0;
            if (j == string::npos)
            {
                n2 = stoi(version2.substr(idx2));
                idx2 = len2;
            }
            else
            {
                n2 = stoi(version2.substr(idx2, j - idx2));
                idx2 = j + 1;
            }
            if (n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
        }
        while (idx1 < len1)
        {
            int i = version1.find_first_of('.', idx1);
            int n1 = 0;
            if (i == string::npos)
            {
                n1 = stoi(version1.substr(idx1));
                idx1 = len1;
            }
            else
            {
                n1 = stoi(version1.substr(idx1, i - idx1));
                idx1 = i + 1;
            }
            if (n1 > 0)
                return 1;
        }
        while (idx2 < len1)
        {
            int j = version2.find_first_of('.', idx2);
            int n2 = 0;
            if (j == string::npos)
            {
                n2 = stoi(version2.substr(idx2));
                idx2 = len2;
            }
            else
            {
                n2 = stoi(version2.substr(idx2, j - idx2));
                idx2 = j + 1;
            }
            if (n2 > 0)
                return -1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string version1;
		walkString(version1, line);
		getline(cin, line);
		string version2;
		walkString(version2, line);
		cout << toString(Solution().compareVersion(version1, version2)) << endl;
	}
	return 0;
}