#include "lc.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &vec : A)
        {
            size_t len = A.size();
            size_t i = 0;
            for ( ; i < len / 2; ++i)
            {
                int left = vec[i];
                int right = vec[len - i - 1];
                left = left ^ 1;
                right = right ^ 1;
                vec[i] = right;
                vec[len - i - 1] = left;
            }
            if (i * 2 < len)
            {
                vec[i] = vec[i] ^ 1;
            }
        }
        return A;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> input;
		walkString(input, line);
    	vector<vector<int>> output = Solution().flipAndInvertImage(input);
		cout << toString(output) << endl;
	}
    return 0;
}
