#include "lc.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int beg = 0, end = len - 1;
        int need_add = 0;
        while (beg <= end)
        {
            int pivot = citations[beg];
            int idx1 = beg + 1;
            int idx2 = end;
            while (idx1 <= idx2)
            {
                while (idx1 <= idx2 && citations[idx1] <= pivot)
                {
                    idx1++;
                }
                while (idx1 <= idx2 && citations[idx2] > pivot)
                {
                    idx2--;
                }
                if (idx1 <= idx2)
                {
                    swap(citations[idx1], citations[idx2]);
                    idx1++; idx2--;
                }
            }
            swap(citations[idx2], citations[beg]);
            if (end - idx2 + 1 + need_add == pivot)
                return pivot;
            else if (end - idx2 + 1 + need_add > pivot)
            {
                beg = idx2 + 1;
            }
            else
            {
                end = idx2 - 1;
                need_add = end - idx2 + 1 + need_add;
            }
        }
        return len - end;
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