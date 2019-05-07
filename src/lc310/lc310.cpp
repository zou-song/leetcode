#include "lc.h"

class Solution {
    typedef list<int> EDGES;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
        {
            return {0};
        }
        unordered_map<int, EDGES> trees;
        for (auto &vec : edges)
        {
            trees[vec[0]].emplace_back(vec[1]);
            trees[vec[1]].emplace_back(vec[0]);
        }
        queue<int> que;
        for (auto iter = trees.begin(); iter != trees.end(); ++iter)
        {
            if (iter->second.size() == 1)
            {
                que.push(iter->first);
            }
        }
        while (trees.size() > 2)
        {
            int que_sz = que.size();
            while (que_sz > 0)
            {
                int e = que.front();
                que.pop();
                auto iter = trees.find(trees[e].front());
                iter->second.remove(e);
                if (iter->second.size() == 1)
                {
                    que.push(iter->first);
                }
                que_sz--;
                trees.erase(e);
            }
        }
        vector<int> ret;
        for (auto &pr : trees)
        {
            ret.push_back(pr.first);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		vector<vector<int>> edges;
		getline(cin, line);
		walkString(edges, line);
		cout << toString(Solution().findMinHeightTrees(n, edges)) << endl;
	}
	return 0;
}