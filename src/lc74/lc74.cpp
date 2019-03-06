#include "lc.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i)
        {
            if (target == matrix[i][cols - 1])
                return true;
            else if (target < matrix[i][cols - 1])
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (target == matrix[i][j])
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while(getline(cin, line))
	{
		vector<vector<int>> matrix;
		walkString(matrix, line);
		getline(cin, line);
		int target = 0;
		walkString(target, line);
		bool output = Solution().searchMatrix(matrix, target);
		cout << toString(output) << endl;
	}
}