#include "lc.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        heights.push_back(0);
        int len = heights.size();
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            while (!stk.empty() && stk.top().second > heights[i])
            {
                pair<int, int> pr = stk.top();
                stk.pop();
                int beg = 0, end = i;
                if (!stk.empty())
                    beg = stk.top().first + 1;
                int area = pr.second * (end - beg);
                ret = (area > ret) ? area : ret;
            }
            stk.emplace(i, heights[i]);
        }
        return ret;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0)  return 0;
        int cols = matrix[0].size();
        if (cols < 0)   return 0;
        vector<int> heights(cols, 0);
        int ret = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int tmp = largestRectangleArea(heights);
            if (tmp > ret)
                ret = tmp;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		std::vector<vector<char>> matrix;
		walkString(matrix, line);
		cout << toString(Solution().maximalRectangle(matrix)) << endl;
	}
	return 0;
}