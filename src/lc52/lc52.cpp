#include "lc.h"

class Solution {
    vector<bool> _cols_flags;
    vector<bool> _dign_flags1;
    vector<bool> _dign_flags2;
    int _total;
public:
    void totalNQueens(int n, int row)
    {
        if (row >= n)
        {
            _total++;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (_cols_flags[i]) continue;
            if (_dign_flags1[row + i]) continue;
            if (_dign_flags2[row - i + n])  continue;
            _cols_flags[i] = true;
            _dign_flags1[row + i] = true;
            _dign_flags2[row - i + n] = true;
            totalNQueens(n, row + 1);
            _cols_flags[i] = false;
            _dign_flags1[row + i] = false;
            _dign_flags2[row - i + n] = false;
        }
    }
    int totalNQueens(int n) {
        _total = 0;
        _cols_flags.resize(n);
        _dign_flags1.resize(n + n);
        _dign_flags2.resize(n + n);
        fill(_cols_flags.begin(), _cols_flags.end(), false);
        fill(_dign_flags1.begin(), _dign_flags1.end(), false);
        fill(_dign_flags2.begin(), _dign_flags2.end(), false);
        totalNQueens(n, 0);
        return _total;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().totalNQueens(n)) << endl;
	}
	return 0;
}