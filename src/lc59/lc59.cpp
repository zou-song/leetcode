#include "lc.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> ret(n);
        for_each(ret.begin(), ret.end(), [n](vector<int> &vec){
            vec.resize(n);
        });
        for (int i = 0; i <= n / 2; ++i)
        {
            int rc = n - i - 1;
            for (int j = i; j <= rc; ++j)
            {
                ret[i][j] = num++;
            }
            int br = n - i - 1;
            for (int j = i + 1; j <= br; ++j)
            {
                ret[j][rc] = num++;
            }
            for (int j = rc - 1; j >= i && br != i; --j)
            {
                ret[br][j] = num++;
            }
            for (int j = br - 1; j > i && rc != i; --j)
            {
                ret[j][i] = num++;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
	string line;
	while (getline(cin, line))
	{
		int input = 0;
		walkString(input, line);
		auto output = Solution().generateMatrix(input);
		cout << toString(output) << endl;
	}
	return 0;
}