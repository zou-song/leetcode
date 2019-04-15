#include "lc.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows <= 0)  return;
        int cols = board[0].size();
        if (cols <= 0)  return;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int stat = 0;
                for (int k = -1; k <= 1; ++k)
                {
                    if (i + k < 0)  continue;
                    if (i + k >= rows)  continue;
                    for (int p = -1; p <= 1; ++p)
                    {
                        if (j + p < 0)  continue;
                        if (j + p >= cols)  continue;
                        if (k == 0 && p == 0)   continue;
                        if (board[i + k][j + p] & 1)
                            stat++;
                    }
                }
                if (stat < 2)
                {
                    if (board[i][j])
                        board[i][j] = 3;
                }
                else if (stat > 3)
                {
                    if (board[i][j])
                        board[i][j] = 3;
                }
                else
                {
                    if (board[i][j] == 0 && stat == 3)
                        board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                if (board[i][j] == 3)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
        }
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> board;
		walkString(board, line);
		Solution().gameOfLife(board);
		cout << toString(board) << endl;
	}
	return 0;
}