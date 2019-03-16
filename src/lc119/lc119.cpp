#include "lc.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex <= 0)  return {1};
        vector<int> ret = {1};
        for (int i = 1; i <= rowIndex; ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < i + 1; ++j)
            {
                int idx1 = j - 1;
                int idx2 = j;
                if (idx1 < 0 || idx2 >= i)
                    tmp.push_back(1);
                else
                    tmp.push_back(ret[idx1] + ret[idx2]);
            }
            swap(ret, tmp);
        }
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		int rowIndex = 0;
		walkString(rowIndex, line);
		cout << toString(Solution().getRow(rowIndex)) << endl;
	}
	return 0;
}