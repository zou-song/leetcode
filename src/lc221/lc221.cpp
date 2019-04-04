#include "lc.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0)  return 0;
        int cols = matrix[0].size();
        if (cols <= 0)  return 0;
        vector<vector<int>> dp(rows);
        for_each(dp.begin(), dp.end(), [cols](vector<int>& vec){
            vec.resize(cols);
        });
        int retLen = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else if (i - 1 < 0 || j - 1 < 0)
                    dp[i][j] = 1;
                else
                {
                    int len = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    dp[i][j] = len + 1;
                }
                if (dp[i][j] > retLen)
                    retLen = dp[i][j];
            }
        }
        return retLen * retLen;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> matrix;
		walkString(matrix, line);
		cout << toString(Solution().maximalSquare(matrix)) << endl;
	}
	return 0;
}