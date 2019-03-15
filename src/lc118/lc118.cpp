#include "lc.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows < 1)    return ret;
        ret.push_back({1});
        if (numRows == 1)   return ret;
        for (int i = 2; i <= numRows; ++i)
        {
            vector<int> vec;
            for (int j = 0; j < i; ++j)
            {
                int idx1 = j - 1;
                int idx2 = j;
                if (idx1 < 0 || idx2 >= (int)ret[i - 2].size())
                    vec.push_back(1);
                else
                    vec.push_back(ret[i - 2][idx1] + ret[i - 2][idx2]);
            }
            ret.push_back(vec);
        }
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		int numRows = 0;
		walkString(numRows, line);
		cout << toString(Solution().generate(numRows)) << endl;
	}
	return 0;
}
