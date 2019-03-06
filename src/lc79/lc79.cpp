#include "lc.h"

class Solution {
public:
    bool exist(const vector<vector<char>> &board, int r, int c, vector<vector<bool>> &mask, const string &word, int idx)
    {
        int len = word.size();
        if (idx >= len)
            return true;
        int rows = board.size();
        int cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;
        if (mask[r][c])
            return false;
        if (board[r][c] != word[idx])
            return false;
        mask[r][c] = true;
        bool ret = exist(board, r, c + 1, mask, word, idx + 1) ||
            exist(board, r, c- 1, mask, word, idx + 1) ||
            exist(board, r + 1, c, mask, word, idx + 1) ||
            exist(board, r - 1, c, mask, word, idx + 1);
        mask[r][c] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> mask(rows);
        for (auto &vec : mask)
        {
            vec.resize(cols);
            fill(vec.begin(), vec.end(), false);
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                bool ret = exist(board, i, j, mask, word, 0);
                if (ret)
                    return ret;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<vector<char>> board;
        walkString(board, line);
        getline(cin, line);
        string target;
        walkString(target, line);
        auto output = Solution().exist(board, word);
        cout << toString(output) << endl;
    }
    return 0;
}