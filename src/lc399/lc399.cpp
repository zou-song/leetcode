#include "lc.h"

class Solution {
    struct Edge;
    struct GraphNode
    {
        string _var;
        vector<Edge> _edges;
        
        GraphNode(const string& str) : _var(str){}
    };
    struct Edge
    {
        GraphNode* _from;
        GraphNode* _to;
        double _val;
        
        Edge(GraphNode* f, GraphNode* t, double v) : _from(f), _to(t), _val(v){}
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, GraphNode*> graph;
        int len = equations.size();
        for (int i = 0; i < len; ++i)
        {
            auto &vars = equations[i];
            auto from_iter = graph.find(vars[0]);
            GraphNode* from = nullptr;
            if (from_iter == graph.end())
            {
                from = new GraphNode(vars[0]);
                graph[vars[0]] = from;
            }
            else
            {
                from = from_iter->second;
            }
            auto to_iter = graph.find(vars[1]);
            GraphNode *to = nullptr;
            if (to_iter == graph.end())
            {
                to = new GraphNode(vars[1]);
                graph[vars[1]] = to;
            }
            else
            {
                to = to_iter->second;
            }
            from->_edges.emplace_back(from, to, values[i]);
            to->_edges.emplace_back(to, from, 1.0 / values[i]);
        }
        
        vector<double> ret;
        for (auto &qry : queries)
        {
            auto from_iter = graph.find(qry[0]);
            auto to_iter = graph.find(qry[1]);
            if (from_iter == graph.end() || to_iter == graph.end())
            {
                ret.emplace_back(-1.0);
                continue;
            }
            GraphNode *from = from_iter->second;
            GraphNode *to = to_iter->second;
            unordered_set<GraphNode*> flags;
            queue<pair<GraphNode*, double>> que;
            que.emplace(from, 1.0);
            flags.emplace(from);
            bool found = false;
            while (!que.empty())
            {
                for (auto &edge : que.front().first->_edges)
                {
                    if (edge._to == to)
                    {
                        found = true;
                        ret.emplace_back(que.front().second * edge._val);
                        break;
                    }
                    if (flags.count(edge._to) == 0)
                    {
                        que.emplace(edge._to, que.front().second * edge._val);
                        flags.emplace(edge._to);
                    }
                }
                que.pop();
                if (found)
                {
                    break;
                }
            }
            if (!found)
            {
                ret.emplace_back(-1.0);
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
		vector<vector<string>> equations;
		walkString(equations, line);
		getline(cin, line);
		vector<double> values;
		walkString(values, line);
		getline(cin, line);
		vector<vector<string>> queries;
		walkString(queries, line);
		cout << toString(Solution().calcEquation(equations, values, queries)) << endl;
	}
	return 0;
}