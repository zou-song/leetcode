#include "lc.h"

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum = 0, f0 = 0;
        long long len = A.size();
        for (int i = 0; i < len; ++i)
        {
            sum += A[i];
            f0 += (i * A[i]);
        }
        long long ret = f0;
        for (int i = 1; i < len; ++i)
        {
            f0 = f0 + (sum - len * A[len - i]);
            if (f0 > ret)
            {
                ret = f0;
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
		vector<int> A;
		walkString(A, line);
		cout << toString(Solution().maxRotateFunction(A)) << endl;
	}
	return 0;
}