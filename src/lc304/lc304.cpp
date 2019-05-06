#include "lc.h"

class NumMatrix {
    vector<vector<int>> _cache;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0)  return;
        int cols = matrix[0].size();
        if (cols <= 0)  return;
        _cache.resize(rows);
        for_each(_cache.begin(), _cache.end(), [cols](vector<int>& vec){
            vec.resize(cols);
        });
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        _cache[i][j] = matrix[i][j];
                    }
                    else
                    {
                        _cache[i][j] = _cache[i][j - 1] + matrix[i][j];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        _cache[i][j] = _cache[i - 1][j] + matrix[i][j];
                    }
                    else
                    {
                        _cache[i][j] = _cache[i - 1][j] - _cache[i - 1][j - 1] + _cache[i][j - 1] + matrix[i][j];
                    }
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
        {
            return _cache[row2][col2];
        }
        else if (row1 == 0)
        {
            return _cache[row2][col2] - _cache[row2][col1 - 1];
        }
        else if (col1 == 0)
        {
            return _cache[row2][col2] - _cache[row1 - 1][col2];
        }
        return _cache[row2][col2] - _cache[row1 - 1][col2] - _cache[row2][col1 - 1] + _cache[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }