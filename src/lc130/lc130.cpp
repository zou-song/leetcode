#include "lc.h"

class Solution {
public:
    struct PairHash
    {
        size_t operator()(const pair<int, int>& pr) const
        {
            return std::hash<int>()(pr.first) ^ std::hash<int>()(pr.second);
        }
    };
    void BFSTag(vector<vector<char>>& board, int i, int j)
    {
        int rows = board.size();
        int cols = board[0].size();
        if (i < 0 || i >= rows) return;
        if (j < 0 || j >= cols) return;
        queue<pair<int, int>> node;
        node.emplace(i, j);
        unordered_set<pair<int, int>, PairHash> tset;
        tset.emplace(i, j);
        while (!node.empty())
        {
            queue<pair<int, int>> tmp;
            while (!node.empty())
            {
                pair<int, int> pr = node.front();
                node.pop();
                board[pr.first][pr.second] = '1';
                if (tset.count(pair<int, int>(pr.first - 1, pr.second)) == 0 && pr.first - 1 >= 0 && board[pr.first - 1][pr.second] == 'O')
                {
                    tmp.emplace(pr.first - 1, pr.second);
                    tset.emplace(pr.first - 1, pr.second);
                }
                if (tset.count(pair<int, int>(pr.first, pr.second - 1)) == 0 && pr.second - 1 >= 0 && board[pr.first][pr.second - 1] == 'O')
                {
                    tmp.emplace(pr.first, pr.second - 1);
                    tset.emplace(pr.first, pr.second - 1);
                }
                if (tset.count(pair<int, int>(pr.first + 1, pr.second)) == 0 && pr.first + 1 < rows && board[pr.first + 1][pr.second] == 'O')
                {
                    tmp.emplace(pr.first + 1, pr.second);
                    tset.emplace(pr.first + 1, pr.second);
                }
                if (tset.count(pair<int, int>(pr.first, pr.second + 1)) == 0 && pr.second + 1 < cols && board[pr.first][pr.second + 1] == 'O')
                {
                    tmp.emplace(pr.first, pr.second + 1);
                    tset.emplace(pr.first, pr.second + 1);
                }
            }
            swap(node, tmp);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows <= 0)  return;
        int cols = board[0].size();
        if (cols <= 0)  return;
        for (int i = 0; i < cols; ++i)
        {
            if (board[0][i] == 'O')
            {
                BFSTag(board, 0, i);
            }
            if (rows - 1 != 0 && board[rows - 1][i] == 'O')
            {
                BFSTag(board, rows - 1, i);
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            if (board[i][0] == 'O')
            {
                BFSTag(board, i, 0);
            }
            if (cols - 1 != 0 && board[i][cols - 1] == 'O')
            {
                BFSTag(board, i, cols - 1);
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> board;
		walkString(board, line);
		cout << toString(Solution().solve(board)) << endl;
	}
	return 0;
}