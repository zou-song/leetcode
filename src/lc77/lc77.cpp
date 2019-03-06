#include "lc.h"

class Solution {
public:
    void combine(int beg, int end, int k, vector<vector<int>> &ret, vector<int> &vec)
    {
        if (k <= 0)
        {
            if (!vec.empty())
                ret.push_back(vec);
            return;
        }
        if (beg > end)
        {
            return;
        }
        for (int i = beg; i <= end; ++i)
        {
            vec.push_back(i);
            combine(i + 1, end, k - 1, ret, vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> vec;
        combine(1, n, k, ret, vec);
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		getline(cin, line);
		int k = 0;
		walkString(k, line);
		vector<vector<int>> output = Solution().combine(n, k);
		cout << toString(output) << endl;
	}
	return 0;
}