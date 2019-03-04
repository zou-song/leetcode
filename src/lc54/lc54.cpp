#include "lc.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> ret;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        for ( ; i < rows / 2 && i < cols / 2; ++i)
        {
            int rc = cols - i - 1;
            for (int j = i; j <= rc; ++j)
                ret.push_back(matrix[i][j]);
            int br = rows - i - 1;
            for (int j = i + 1; j <= br; ++j)
                ret.push_back(matrix[j][rc]);
            for (int j = rc - 1; j >= i && br != i; --j)
                ret.push_back(matrix[br][j]);
            for (int j = br - 1; j > i && rc != i; --j)
                ret.push_back(matrix[j][i]);
        }
        if (2 * i < rows && 2 * i < cols)
        {
            int rc = cols - i - 1;
            for (int j = i; j <= rc; ++j)
                ret.push_back(matrix[i][j]);
            int br = rows - i - 1;
            for (int j = i + 1; j <= br; ++j)
                ret.push_back(matrix[j][rc]);
            for (int j = rc - 1; j >= i && br != i; --j)
                ret.push_back(matrix[br][j]);
            for (int j = br - 1; j > i && rc != i; --j)
                ret.push_back(matrix[j][i]);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> input;
		walkString(input, line);
		vector<int> output = Solution().spiralOrder(input);
		cout << toString(output) << endl;
	}
	return 0;
}