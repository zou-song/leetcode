#include "lc.h"

class Solution {
public:
#define BASESIZE 3
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<unsigned int> uns(1,1);
        const unsigned int bases[BASESIZE] = {2, 3, 5};
        list<int> cmps = {0};
        int idxofcmps = 0;
        while (uns.size() < (size_t)n)
        {
            int idx = idxofcmps;
            auto iter = cmps.begin();
            auto min_iter = iter;
            unsigned int min_num = INT_MAX;
            while (idx < (int)uns.size() && iter != cmps.end())
            {
                unsigned int num = uns[idx] * bases[*iter];
                if (num < min_num)
                {   
                    min_num = num;
                    min_iter = iter;
                }
                ++iter;
                idx++;
            }
            if (min_num <= uns.back())
            {
				if (*min_iter == 0)
				{
					cmps.push_back(0);
				}
                if (++*min_iter >= BASESIZE)
                {
                    cmps.erase(min_iter);
                    idxofcmps++;
                }
            }
            else
            {
                uns.push_back(min_num);
                if (*min_iter == 0)
                {
                    ++*min_iter;
                    cmps.push_back(0);
                }
                else if (*min_iter == BASESIZE - 1)
                {
                    cmps.erase(min_iter);
                    idxofcmps++;
                }
                else    ++*min_iter;
            }
        }
        return uns.back();
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		cout << toString(Solution().nthUglyNumber(n)) << endl;
	}
	return 0;
}
