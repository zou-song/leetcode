#include "lc.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)   return s;
        bool ascend = false;
        vector<vector<char>> vec(numRows);
        int row = 0, col = 0;
        for (char c : s)
        {
            vector<char> &v = vec[row];
            while (v.size() <= col)
                v.emplace_back('\0');
            vec[row][col] = c;
            if (ascend)
            {
                if (row == 0)
                {
                    ascend = false;
                    row++;
                }
                else
                {
                    row--;
                    col++;
                }
            }
            else
            {
                if (row == numRows - 1)
                {
                    ascend = true;
                    row--;
                    col++;
                }
                else
                {
                    row++;
                }
            }
        }
        string ret;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < vec[i].size(); ++j)
                if (vec[i][j] != '\0')
                    ret.push_back(vec[i][j]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		int numRows = 0;
		getline(cin, line);
		walkString(numRows, line);
		cout << toString(Solution().convert(s, numRows)) << endl;
	}
	return 0;
}