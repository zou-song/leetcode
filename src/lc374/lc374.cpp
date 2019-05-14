#include "lc.h"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int beg = 1, end = n;
        while (beg <= end)
        {
            int mid = ((unsigned int)beg + end) / 2;
            int res = guess(mid);
            if (res == 0)
            {
                return mid;
            }
            else if (res > 0)
            {
                beg = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return beg;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}