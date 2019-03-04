#include "lc.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> ret;
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        for (size_t i = 0; i < rows / 2 && i < cols / 2; ++i)
        {
            size_t rc = cols - i - 1;
            for (size_t j = i; j <= rc; ++j)
                ret.push_back(matrix[i][j]);
            size_t br = rows - i - 1;
            for (size_t j = i + 1; j <= br; ++j)
                ret.push_back(matrix[j][rc]);
            for (size_t j = rc - 1; j >= i; --j)
                ret.push_back(matrix[br][j]);
            for (size_t j = br - 1; j > i; --j)
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