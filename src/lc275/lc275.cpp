#include "lc.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int beg = 0, end = len - 1;
        int need_add = 0;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (end - mid + 1 + need_add == citations[mid])
                return citations[mid];
            else if (end - mid + 1 + need_add > citations[mid])
                beg = mid + 1;
            else
            {
                need_add = end - mid + 1 + need_add;
                end = mid - 1;
            }
        }
        return len - end - 1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> citations;
		walkString(citations, line);
		cout << toString(Solution().hIndex(citations)) << endl;
	}
	return 0;
}