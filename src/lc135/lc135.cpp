#include "lc.h"

class Solution {
public:
    int candy1(vector<int>& ratings) {
        typedef pair<vector<int>, int> PAIR;
        vector<PAIR> vec;
        int len = ratings.size();
        if (len < 1)    return 0;
        PAIR pr;
        pr.first.push_back(1);
        pr.second = INT_MAX;
        vec.push_back(pr);
        for (int i = 1; i < len; ++i)
        {
            auto &pr = vec.back();
            if (ratings[i] > ratings[i - 1])
            {
                pr.first.push_back(pr.first.back() + 1);
            }
            else if (ratings[i] < ratings[i - 1])
            {
                PAIR p;
                p.second = pr.first.back();
                p.first.push_back(1);
                vec.push_back(p);
            }
            else
            {
                PAIR p;
                p.second = INT_MAX;
                p.first.push_back(1);
                vec.push_back(p);
            }
        }
        int pre_add = 0;
        int ret = 0;
        while (!vec.empty())
        {
            auto &pr = vec.back();
            int cnt = pr.first.size();
            int sum = cnt * (1 + cnt) / 2 + pre_add;
            pr.first.back() += pre_add;
            int minelem = pr.first.front();
            if (minelem >= pr.second)
            {
                pre_add = minelem - pr.second + 1;
            }
            else
            {
                pre_add = 0;
            }
            ret += sum;
            vec.pop_back();
        }
        return ret;
    }
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> vec(len, 1);
        for (int i = 1; i < len; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                vec[i] = vec[i - 1] + 1;
            }
        }
        for (int i = len - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                vec[i] = max(vec[i], vec[i + 1] + 1);
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> ratings;
		walkString(ratings, line);
		cout << toString(Solution().candy(ratings)) << endl;
	}
	return 0;
}