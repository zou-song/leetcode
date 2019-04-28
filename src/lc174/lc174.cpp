#include "lc.h"

class Solution {
public:
    void func(const vector<vector<int>>& dungeon, int r, int c, int init, int sum, int& ret)
    {
        if (init >= ret)    return;
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        if (r == rows - 1 && c == cols - 1)
        {
            sum += dungeon[r][c];
            if (sum < 1)
            {
                init = (1 - sum) + init;
                sum = 1;
            }
            if (init < ret)
            {
                ret = init;
            }
            return;
        }
        else if (r >= rows)   return;
        else if (c >= cols)   return;
        
        sum += dungeon[r][c];
        if (sum < 1)
        {
            init = (1 - sum) + init;
            sum = 1;
        }
        func(dungeon, r + 1, c, init, sum, ret);
        func(dungeon, r, c + 1, init, sum, ret);
    }
    struct GraphNode
    {
        int _i, _j;
        int _init;
        int _sum;
        int _times;
    };
    int dfs(const vector<vector<int>>& dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        int ret = INT_MAX;
        stack<GraphNode> stk;
        GraphNode node;
        node._i = node._j = 0;
        node._times = 0;
        if (dungeon[0][0] >= 0)
        {
            node._init = 1;
            node._sum = 1 + dungeon[0][0];
        }
        else
        {
            node._init = 1 - dungeon[0][0];
            node._sum = 1;
        }
        stk.push(node);
        while (!stk.empty())
        {
            if (stk.top()._i == rows - 1 && stk.top()._j == cols - 1)
            {
                if (stk.top()._init < ret)
                {
                    ret = stk.top()._init;
                }
                stk.pop();
            }
            else if (stk.top()._init >= ret)
            {
                stk.pop();
            }
            else if (stk.top()._times == 0)
            {//right
                ++stk.top()._times;
                GraphNode n = stk.top();
                n._times = 0;
                if(++n._j >= cols)  continue;
                n._sum += dungeon[n._i][n._j];
                if (n._sum < 1)
                {
                    n._init += (1 - n._sum);
                    n._sum = 1;
                }
                stk.push(n);
            }
            else if (stk.top()._times == 1)
            {//down
                ++stk.top()._times;
                GraphNode n = stk.top();
                n._times = 0;
                if (++n._i >= rows) continue;
                n._sum += dungeon[n._i][n._j];
                if (n._sum < 1)
                {
                    n._init += (1 - n._sum);
                    n._sum = 1;
                }
                stk.push(n);
            }
            else
            {
                stk.pop();
            }
        }
        return ret;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        if (rows <= 0)  return 0;
        int cols = dungeon[0].size();
        if (cols <= 0)  return 0;
        vector<vector<int>> dp(rows + 1);
        for_each(dp.begin(), dp.end(), [cols](vector<int>& vec){
            vec.resize(cols + 1);
            fill(vec.begin(), vec.end(), INT_MAX);
        });
        dp[rows][cols - 1] = dp[rows - 1][cols] = 0;
        for (int i = rows - 1; i >= 0; --i)
        {
            for (int j = cols - 1; j >= 0; --j)
            {
                dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 0);
            }
        }
        return dp[0][0] + 1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> dungeon;
		walkString(dungeon, line);
		cout << toString(Solution().calculateMinimumHP(dungeon)) << endl;
	}
	return 0;
}