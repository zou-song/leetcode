#include "lc.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ret;
        long long n = numerator, d = denominator;
        bool neg = false;
        if (n < 0)
        {
            n = -n;
            neg = !neg;
        }
        if (d < 0)
        {
            d = -d;
            neg = !neg;
        }
        if (neg)
        {
            ret = "-";
        }
        if (n >= d)
        {
            ret = ret + to_string(n / d);
            n = n % d;
        }
        else
        {
            ret = ret + "0";
        }
        if (n == 0)
        {
            return ret;
        }
        ret += ".";
        unordered_map<int, int> hashmap;
        while (n)
        {
            n *= 10;
            auto iter = hashmap.find(n);
            if (iter != hashmap.end())
            {//repeated
                ret = ret.substr(0, iter->second) + "(" + ret.substr(iter->second) + ")";
                return ret;
            }
            if (n < d)
            {
                ret += "0";
                hashmap[n] = ret.size() - 1;
            }
            else
            {
                ret += to_string(n / d);
                hashmap[n] = ret.size() - 1;
                n = n % d;
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
		int numerator = 0, denominator = 0;
		walkString(numerator, line);
		getline(cin, line);
		walkString(denominator, line);
		cout << toString(Solution().fractionToDecimal(numerator, denominator)) << endl;
	}
	return 0;
}