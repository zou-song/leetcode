#include "lc.h"

class Solution {
    struct ELEM
    {
        int i;
        int j;
        int val;
        ELEM(int x, int y, int v) : i(x), j(y), val(v) {}
    };
    struct Cmp
    {
        bool operator ()(const ELEM& lhs, const ELEM& rhs) const
        {
            return lhs.val > rhs.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<ELEM, vector<ELEM>, Cmp> pri_que;
        int rows = matrix.size();
        if (rows <= 0)
        {
            return 0;
        }
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i)
        {
            pri_que.emplace(i, 0, matrix[i][0]);
        }
        while (--k > 0)
        {
            ELEM elem = pri_que.top();
            pri_que.pop();
            if (++elem.j < cols)
            {
                pri_que.emplace(elem.i, elem.j, matrix[elem.i][elem.j]);
            }
        }
        return pri_que.top().val;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> matrix;
		walkString(matrix, line);
		int k = 0;
		getline(cin, line);
		walkString(k, line);
		cout << toString(Solution().kthSmallest(matrix, k)) << endl;
	}
	return 0;
}