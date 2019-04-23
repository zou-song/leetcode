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
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> heights;
		walkString(heights, line);
		cout << toString(Solution().largestRectangleArea(heights)) << endl;
	}
	return 0;
}