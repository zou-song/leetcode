#include "lc.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 10;
        }
        int sum = 10;
        unsigned int pre = 9, k = 9;
        for (int i = 2; i <= n && k >= 1; ++i)
        {
            pre = pre * k;
            k--;
            sum += pre;
        }
        return sum;
    }
};