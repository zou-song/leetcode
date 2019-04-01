#include "lc.h"

class Solution {
    typedef vector<int> NODE;
    struct NODEHash
    {
        size_t operator()(const NODE& nd) const
        {
            size_t ret = 0;
            for (int n : nd)
                ret = ret ^ std::hash<int>()(n);
            return ret;
        }
    };
    struct NODEEqual
    {
        bool operator()(const NODE& lhs, const NODE& rhs) const
        {
            int lret = 0, rret = 0;
            for (int n : lhs)
                lret += (n * n);
            for (int n : rhs)
                rret += (n * n);
            return lret == rret;
        }
    };
public:
    bool isHappy(int n) {
        unordered_set<NODE, NODEHash, NODEEqual> uset;
        while (n != 1)
        {
            NODE nd;
            while (n)
            {
                nd.push_back(n % 10);
                n /= 10;
            }
            if (uset.count(nd))
                return false;
            uset.insert(nd);
            for (int i : nd)
                n += (i * i);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().isHappy(n)) << endl;
	}
	return 0;
}