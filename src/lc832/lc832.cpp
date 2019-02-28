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
    vector<vector<int>> input = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    vector<vector<int>> expected = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> output = Solution().flipAndInvertImage(input);
	cout << "expected and output are " << ((expected == output) ? "true" : "false") << endl;
    return 0;
}
