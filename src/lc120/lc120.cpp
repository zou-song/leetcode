#include "lc.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows < 1)   return 0;
        vector<int> vec = {triangle[0][0]};
        for (int i = 1; i < rows; ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < i + 1; ++j)
            {
                int idx1 = j - 1;
                int idx2 = j;
                if (idx1 < 0)
                    tmp.push_back(vec[idx2] + triangle[i][j]);
                else if (idx2 >= i)
                    tmp.push_back(vec[idx1] + triangle[i][j]);
                else
                    tmp.push_back(min(vec[idx1], vec[idx2]) + triangle[i][j]);
            }
            swap(vec, tmp);
        }
        return *min_element(vec.begin(), vec.end());
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> triangle;
		walkString(triangle, line);
		cout << toString(Solution().minimumTotal(triangle)) << endl;
	}
	return 0;
}