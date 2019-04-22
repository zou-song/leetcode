#include "lc.h"

class Solution {
    vector<vector<bool>> _grid_flags;
    vector<vector<bool>> _rows_flags;
    vector<vector<bool>> _cols_flags;
public:
    #define GETGRIDINDEX(i, j)  (i / 3 * 3 + j / 3)
    
    bool solveSudoku(vector<vector<char>>& board, int i, int j)
    {
        int grid_idx = GETGRIDINDEX(i, j);
        for (int k = 1; k <= 9; ++k)
        {
            if (_grid_flags[grid_idx][k])   continue;
            if (_rows_flags[i][k])  continue;
            if (_cols_flags[j][k])  continue;
            
            board[i][j] = '0' + k;
            _grid_flags[grid_idx][k] = true;
            _rows_flags[i][k] = true;
            _cols_flags[i][k] = true;
            
            int x = i, y = j;
            while (x < 9)
            {
                while (y < 9)
                {
                    if (board[x][y] == '.')
                        break;
                    y++;
                }
                if (y >= 9)
                {
                    y = 0;
                    x++;
                }
                else break;
            }
            if (x >= 9 || y >= 9)
            {
                return true;
            }
            bool ret = solveSudoku(board, x, y);
            if (!ret)
            {
                board[i][j] = '.';
                _grid_flags[grid_idx][k] = false;
                _rows_flags[i][k] = false;
                _cols_flags[i][k] = false;
            }
            else return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        _grid_flags.resize(9);
        _rows_flags.resize(9);
        _cols_flags.resize(9);
        for (int i = 0; i < 9; ++i)
        {
            _grid_flags[i].resize(10);
            _rows_flags[i].resize(10);
            _cols_flags[i].resize(10);
            fill(_grid_flags[i].begin(), _grid_flags[i].end(), false);
            fill(_rows_flags[i].begin(), _rows_flags[i].end(), false);
            fill(_cols_flags[i].begin(), _cols_flags[i].end(), false);
            int grid_x = i / 3 * 3;
            int grid_y = (i - grid_x) * 3;
            for (int x = 0; x < 3; ++x)
            {
                for (int y = 0; y < 3; ++y)
                {
                    if (board[grid_x + x][grid_y + y] != '.')
                        _grid_flags[i][board[grid_x + x][grid_y + y] - '0'] = true;
                }
            }
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                    _rows_flags[i][board[i][j] - '0'] = true;
            }
            for (int j = 0; j < 9; ++j)
            {
                if (board[j][i] != '.')
                    _cols_flags[i][board[j][i] - '0'] = true;
            }
        }
        int x = 0, y = 0;
        for (x = 0; x < 9; ++x)
        {
            for (y = 0; y < 9; ++y)
            {
                if (board[x][y] == '.')
                    break;
            }
            if (y < 9)
                break;
        }
        if (x < 9 && y < 9)
            solveSudoku(board, x, y);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> board;
		walkString(board, line);
		Solution().solveSudoku(board);
		cout << toString(board) << endl;
	}
	return 0;
}