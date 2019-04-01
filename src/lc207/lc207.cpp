#include "lc.h"

class Solution {
    struct VertexInfo
    {
        int _in_degree;
        vector<int> _edges;
        
        VertexInfo() : _in_degree(0){}
    };
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<VertexInfo> vinfo(numCourses);
        for (auto &pre : prerequisites)
        {
            vinfo[pre.first]._in_degree++;
            vinfo[pre.second]._edges.push_back(pre.first);
        }
        stack<int> stk;
        for (int i = 0; i < numCourses; ++i)
        {
            if (vinfo[i]._in_degree == 0)
            {
                stk.push(i);
            }
        }
        int cnt = 0;
        while (!stk.empty())
        {
            int idx = stk.top();
            stk.pop();
            cnt++;
            for (int i : vinfo[idx]._edges)
            {
                if (--vinfo[i]._in_degree == 0)
                    stk.push(i);
            }
        }
        if (cnt < numCourses)
            return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int numCourses = 0;
		walkString(numCourses, line);
		vector<pair<int, int>> prerequisites;
		getline(cin, line);
		walkString(prerequisites, line);
		cout << toString(Solution().canFinish(numCourses, prerequisites)) << endl;
	}
	return 0;
}