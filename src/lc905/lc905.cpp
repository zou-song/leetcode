#include "lc.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        size_t len = A.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            if (A[left] % 2 == 0)
                ++left;
            else
            {
                swap(A[left], A[right]);
                --right;
            }
        }
        return A;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        
        vector<int> ret = Solution().sortArrayByParity(A);

        string out = integerVectorToString(ret);
        cout << out << endl;
	}
	return 0;
}
