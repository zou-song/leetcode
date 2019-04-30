#include "lc.h"

class Solution {
    typedef pair<int/*height*/, int/*ri*/> PAIR;
    struct lesser
    {
        bool operator()(const PAIR& lhs, const PAIR& rhs) const
        {
            return lhs.first < rhs.first;
        }
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int len = buildings.size();
        if (len <= 0)   return {};
        priority_queue<PAIR, vector<PAIR>, lesser> pri_que;
        vector<pair<int, int>> ret;
        for (int i = 0; i < len; ++i)
        {
            int lx = buildings[i][0];
            int rx = buildings[i][1];
            int h = buildings[i][2];
            while (!pri_que.empty() && lx > pri_que.top().second)
            {
                int x = pri_que.top().second;
                pri_que.pop();
                while (!pri_que.empty() && x >= pri_que.top().second)
                {
                    pri_que.pop();
                }
                if (pri_que.empty())
                {
                    ret.emplace_back(x, 0);
                }
                else
                {
                    ret.emplace_back(x, pri_que.top().first);
                }
            }
            if (pri_que.empty())
            {
                ret.emplace_back(lx, h);
                pri_que.emplace(h, rx);
            }
            else if (h > pri_que.top().first)
            {
                ret.emplace_back(lx, h);
                pri_que.emplace(h, rx);
            }
            else
            {
                pri_que.emplace(h, rx);
            }
        }
        while (!pri_que.empty())
        {
            int x = pri_que.top().second;
            pri_que.pop();
            while (!pri_que.empty() && x >= pri_que.top().second)
            {
                pri_que.pop();
            }
            if (pri_que.empty())
            {
                ret.emplace_back(x, 0);
            }
            else
            {
                ret.emplace_back(x, pri_que.top().first);
            }
        }
        vector<vector<int>> tmp;
        int idx = 0;
        int len1 = ret.size();
        while (idx < len1)
        {
            int end = idx + 1;
            int h = ret[idx].second;
            while (end < len1 && ret[end].first == ret[idx].first)
            {
                if (ret[end].second > h)
                {
                    h = ret[end].second;
                }
                end++;
            }
            idx = end - 1;
            while (end < len1 && ret[end].second == h)
            {
                end++;
            }
            vector<int> vec = {ret[idx].first, h};
            tmp.push_back(vec);
            idx = end;
        }
        return tmp;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> buildings;
		walkString(buildings, line);
		cout << toString(Solution().getSkyline(buildings)) << endl;
	}
	return 0;
}