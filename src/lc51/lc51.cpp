#include "lc.h"

class Solution {
    vector<bool> _cols_flags;
    vector<bool> _dign_flags1;
    vector<bool> _dign_flags2;
public:
    void solveNQueens(vector<string>& board, int n, int row, vector<vector<string>>& ret)
    {
        if (row >= n)
        {
            ret.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (_cols_flags[i]) continue;
            if (_dign_flags1[row + i]) continue;
            if (_dign_flags2[row - i + n])  continue;
            string str(n, '.');
            str[i] = 'Q';
            board.push_back(str);
            _cols_flags[i] = true;
            _dign_flags1[row + i] = true;
            _dign_flags2[row - i + n] = true;
            solveNQueens(board, n, row + 1, ret);
            board.pop_back();
            _cols_flags[i] = false;
            _dign_flags1[row + i] = false;
            _dign_flags2[row - i + n] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        _cols_flags.resize(n);
        _dign_flags1.resize(n + n);
        _dign_flags2.resize(n + n);
        fill(_cols_flags.begin(), _cols_flags.end(), false);
        fill(_dign_flags1.begin(), _dign_flags1.end(), false);
        fill(_dign_flags2.begin(), _dign_flags2.end(), false);
        vector<vector<string>> ret;
        vector<string> board;
        solveNQueens(board, n, 0, ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().solveNQueens(n)) << endl;
	}
	return 0;
}