#include "lc.h"

class Solution {
public:
    int countDigitOne(int n) {
        static unordered_map<int, int> hashmap;
        auto iter = hashmap.find(n);
        if (iter != hashmap.end())
        {
            return iter->second;
        }
        if (n < 1)
        {
            return 0;
        }
        else if (n < 10)
        {
            return 1;
        }
        int tmp = 10;
        while (n >= tmp && INT_MAX / 10 > tmp)
        {
            tmp = tmp * 10;
        }
        if (tmp > n)
        {
            tmp /= 10;
        }
        int a = n / tmp;
        int b = n % tmp;
        if (a == 1)
        {
            int c = countDigitOne(b);
            int d = countDigitOne(tmp - 1);
            int ret = c + d + b + 1;
            hashmap[n] = ret;
            return ret;
        }
        int c = countDigitOne(tmp - 1);
        int ret = c + tmp;
        int k = 1;
        while (a > k)
        {
            ret += c;
            k++;
        }
        int d = countDigitOne(b);
        ret += d;
        hashmap[n] = ret;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().countDigitOne(n)) << endl;
	}
	return 0;
}