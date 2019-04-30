#include "lc.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0) return {};
        typedef pair<vector<int>, int> PAIR;
        vector<PAIR> vec;
        for (int i = 1; i <= 9; ++i)
        {
            PAIR pr = {{i}, i};
            vec.push_back(pr);
        }
        for (int i = 1; i < k; ++i)
        {
            vector<PAIR> tmp;
            for (auto &v : vec)
            {
                if (v.second > n)   continue;
                int back = v.first.back();
                for (int j = back + 1; j <= 9; ++j)
                {
					PAIR pr = v;
                    pr.first.push_back(j);
                    pr.second += j;
					if (pr.second <= n)
					{
						tmp.push_back(pr);
					}
                }
            }
            swap(vec, tmp);
        }
        vector<vector<int>> ret;
        for_each(vec.begin(), vec.end(), [&ret, n](const PAIR& pr){
            if (pr.second == n)
            {
                ret.push_back(pr.first);
            }
        });
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int k = 0, n = 0;
		walkString(k, line);
		getline(cin, line);
		walkString(n, line);
		cout << toString(Solution().combinationSum3(k, n)) << endl;
	}
	return 0;
}
