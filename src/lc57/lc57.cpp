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

	string toStr() const
	{
		vector<int> tmp = {start, end};
		return toString(tmp);
	}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        int idx = 0;
        vector<Interval> ret;
        while (idx < len)
        {
            if (intervals[idx].start > newInterval.start)
            {
                break;
            }
            ++idx;
        }
        for (int i = 0; i < idx; ++i)
        {
            ret.push_back(intervals[i]);
        }
        if (!ret.empty() && ret.back().end >= newInterval.start)
        {
            ret.back().end = (ret.back().end < newInterval.end) ? newInterval.end : ret.back().end;
        }
        else
            ret.push_back(newInterval);
        for (int i = idx; i < len; ++i)
        {
            if (intervals[i].start <= ret.back().end)
            {
                ret.back().end = (ret.back().end < intervals[i].end) ? intervals[i].end : ret.back().end;
            }
            else
                ret.push_back(intervals[i]);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line1;
	while (getline(cin, line1))
	{
		vector<Interval> input1;
		walkString(input1, line1);
		string line2;
		getline(cin, line2);
		Interval input2;
		walkString(input2, line2);
		vector<Interval> output = Solution().insert(input1, input2);
		cout << toString(output) << endl;
	}
	return 0;
}
