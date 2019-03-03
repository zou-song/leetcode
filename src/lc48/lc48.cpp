#include "lc.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = i; j < n - i - 1; ++j)
            {
                int tmp = matrix[i][j];
                int x = i, y = j;
                for (int k = 0; k < 3; ++k)
                {
                    int pre_x = n - y - 1;
                    int pre_y = x;
                    matrix[x][y] = matrix[pre_x][pre_y];
                    x = pre_x;  y = pre_y;
                }
                matrix[x][y] = tmp;
            }
        }
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        vector<vector<int>> matrix = stringToIntegerVectorVector(line);
        Solution().rotate(matrix);
        cout << intergerVectorVectorToString(matrix) << endl;
	}
	return 0;
}