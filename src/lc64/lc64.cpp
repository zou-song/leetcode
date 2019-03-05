#include "lc.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> pathsum(rows);
        for_each(pathsum.begin(), pathsum.end(), [cols](vector<int> &vec){
            vec.resize(cols);
        });
        pathsum[0][0] = grid[0][0];
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == 0 && j == 0)   continue;
                int v1 = 0, v2 = 0;
                if (j - 1 >= 0)
                    v1 = pathsum[i][j - 1];
                else    v1 = INT_MAX;
                if (i - 1 >= 0)
                    v2 = pathsum[i - 1][j];
                else    v2 = INT_MAX;
                pathsum[i][j] = min(v1, v2) + grid[i][j];
            }
        }
        return pathsum[rows - 1][cols - 1];
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> input;
		walkString(input, line);
		int output = Solution().minPathSum(input);
		cout << toString(output) << endl;
	}
	return 0;
}