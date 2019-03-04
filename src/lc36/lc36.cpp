#include "lc.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows_used[9][9] = {false};
        bool cols_used[9][9] = {false};
        bool grid_used[9][9] = {false};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                int k = (i / 3) * 3 + j / 3;
                if (rows_used[i][num] || cols_used[j][num] || grid_used[k][num])
                    return false;
                rows_used[i][num] = cols_used[j][num] = grid_used[k][num] = true;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> input;
		walkString(input, line);
		bool output = Solution().isValidSudoku(input);
		cout << toString(output) << endl;
	}
	return 0;
}
