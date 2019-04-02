#include "lc.h"

class Solution {
    struct VertexNode
    {
        int _in_degree;
        list<int> _edges;
        
        VertexNode() : _in_degree(0) {}
    };
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<VertexNode> vinfo(numCourses);
        for (auto &pr : prerequisites)
        {
            vinfo[pr.first]._in_degree++;
            vinfo[pr.second]._edges.push_back(pr.first);
        }
        vector<int> ret;
        stack<int> stk;
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i)
        {
            if (vinfo[i]._in_degree == 0)
                stk.push(i);
        }
        while (!stk.empty())
        {
            int idx = stk.top();
            stk.pop();
            cnt++;
            ret.push_back(idx);
            for (auto iter = vinfo[idx]._edges.begin(); iter != vinfo[idx]._edges.end(); )
            {
                if (--vinfo[*iter]._in_degree == 0)
                {
                    stk.push(*iter);
                    iter = vinfo[idx]._edges.erase(iter);
                }
                else
                    ++iter;
            }
        }
        if (cnt < numCourses)   return {};
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int numCourses = 0;
		walkString(numCourses, line);
		getline(cin, line);
		vector<pair<int, int>> prerequisites;
		walkString(prerequisites, line);
		cout << toString(Solution().findOrder(numCourses, prerequisites)) << endl;
	}
	return 0;
}
