#include "lc.h"

class Solution {
    struct pairHash
    {
        size_t operator()(const pair<int, int>& pr) const
        {
            return std::hash<int>()(pr.first) ^ std::hash<int>()(pr.second);
        }
    };
public:
    void BFSLabelIsland(vector<vector<char>>& grid, int i, int j)
    {
        unordered_set<pair<int, int>, pairHash> uset;
        queue<pair<int, int>> que;
        que.emplace(i, j);
        uset.emplace(i, j);
        int rows = grid.size();
        int cols = grid[0].size();
        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();
            grid[i][j] = '2';
            if (i - 1 >= 0 && uset.count(pair<int, int>(i - 1, j)) == 0 && grid[i- 1][j] == '1')
            {
                uset.emplace(i - 1, j);
                que.emplace(i - 1, j);
            }
            if (i + 1 < rows && uset.count(pair<int, int>(i + 1, j)) == 0 && grid[i + 1][j] == '1')
            {
                uset.emplace(i + 1, j);
                que.emplace(i + 1, j);
            }
            if (j - 1 >= 0 && uset.count(pair<int, int>(i, j - 1)) == 0 && grid[i][j - 1] == '1')
            {
                uset.emplace(i, j - 1);
                que.emplace(i, j - 1);
            }
            if (j + 1 < cols && uset.count(pair<int, int>(i, j + 1)) == 0 && grid[i][j + 1] == '1')
            {
                uset.emplace(i, j + 1);
                que.emplace(i, j + 1);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int rows = grid.size();
        if (rows <= 0)  return 0;
        int cols = grid[0].size();
        if (cols <= 0)  return 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ret++;
                    BFSLabelIsland(grid, i, j);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> grid;
		walkString(grid, line);
		cout << toString(Solution().numIslands(grid)) << endl;
	}
	return 0;
}
