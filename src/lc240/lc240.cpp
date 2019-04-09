#include "lc.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows <= 0)  return false;
        int cols = matrix[0].size();
        if (cols <= 0)  return false;
        int r = 0, c = cols - 1;
        while (r < rows && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                r++;
            else
                c--;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> matrix;
		walkString(matrix, line);
		getline(cin, line);
		int target = 0;
		walkString(target, line);
		cout << toString(Solution().searchMatrix(matrix, target)) << endl;
	}
	return 0;
}