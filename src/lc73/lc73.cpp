#include "lc.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
        bool row1st = false, col1st = false;
        for (size_t i = 0; i < rows; ++i)
            if (matrix[i][0] == 0)
            {
                col1st = true;
                break;
            }
        for (size_t j = 0; j < cols; ++j)
            if (matrix[0][j] == 0)
            {
                row1st = true;
                break;
            }
        for (size_t i = 1; i < rows; ++i)
        {
            for (size_t j = 1; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (size_t i = 1; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for (size_t j = 1; j < cols; ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (size_t i = 0; i < rows; ++i)
                    matrix[i][j] = 0;
            }
        }
        if (row1st)
        {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (col1st)
        {
            for (size_t i = 0; i < rows; ++i)
                matrix[i][0] = 0;
        }
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> matrix;
		walkString(matrix, line);
		Solution().setZeroes(matrix);
		cout << toString(matrix) << endl;
	}
	return 0;
}