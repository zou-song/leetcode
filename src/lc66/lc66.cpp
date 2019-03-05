#include "lc.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int pre_plus = digits[len - 1] + 1;
        int idx = len - 1;
        while (pre_plus > 0 && idx >= 0)
        {
            digits[idx] = pre_plus % 10;
            pre_plus /= 10;
        }
        if (pre_plus > 0)
        {
            digits.insert(digits.begin(), pre_plus);
        }
        return digits;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}