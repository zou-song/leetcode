#include "lc.h"

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

	void parseFromString(string &str)
	{
		vector<int> tmp;
		walkString(tmp, str);
		start = tmp[0];
		end = tmp[1];
	}

	string toString() const
	{
		vector<int> tmp = {start, end};
		return toString(tmp);
	}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
            return lhs.start < rhs.start;
        });
        vector<Interval> ret;
        for (auto &itv : intervals)
        {
            auto iter = find_if(ret.rbegin(), ret.rend(), [&itv](const Interval& v){
                return itv.start <= v.end;
            });
            if (iter == ret.rend())
            {
                Interval nitv(itv.start, itv.end);
                ret.push_back(nitv);
            }
            else
            {
                iter->end = (itv.end > iter->end) ? itv.end : iter->end;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<Interval> input;
		walkString(input, line);
		vector<Interval> output = Solution().merge(input);
		cout << toString(output) << endl;
	}
	return 0;
}