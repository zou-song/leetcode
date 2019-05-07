#include "lc.h"

class Solution {
    typedef list<int> EDGES;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<EDGES> edge_list(n);
        for (auto &vec : edges)
        {
            edge_list[vec[0]].emplace_back(vec[1]);
            edge_list[vec[1]].emplace_back(vec[0]);
        }
        int height = n;
        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            int h = 0;
            vector<bool> labels(n, true);
            labels[i] = false;
            list<int> children(edge_list[i].begin(), edge_list[i].end());
            while (!children.empty())
            {
                list<int> tmp;
                for (int j : children)
                {
                    for (int k : edge_list[j])
                    {
                        if (labels[k])
                        {
                            tmp.emplace_back(k);
                        }
                    }
                    labels[j] = false;
                }
                swap(children, tmp);
                h++;
            }
            if (h < height)
            {
                ret = {i};
            }
            else if (h == height)
            {
                ret.emplace_back(i);
            }
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