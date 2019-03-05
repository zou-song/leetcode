#include "lc.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> flag(rows);
        for_each(flag.begin(), flag.end(), [cols](vector<int> &v){
            v.resize(cols);
        });
        flag[rows - 1][cols - 1] = (obstacleGrid[rows - 1][cols - 1] == 1) ? 0 : 1;
        for (int i = rows - 1; i >= 0; --i)
        {
            for (int j = cols - 1; j >= 0; --j)
            {
                if (i == rows - 1 && j == cols - 1) continue;
                int v1 = 0, v2 = 0;
                if (j + 1 < cols)
                    v1 = flag[i][j + 1];
                if (i + 1 < rows)
                    v2 = flag[i + 1][j];
                flag[i][j] = (obstacleGrid[i][j] == 1) ? 0 : (v1 + v2);
            }
        }
        return flag[0][0];
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> input;
		walkString(input, line);
		int output = Solution().uniquePathsWithObstacles(input);
		cout << toString(output) << endl;
	}
	return 0;
}