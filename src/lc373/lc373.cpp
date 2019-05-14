#include "lc.h"

class Solution {
    struct ELEM
    {
        int idx1;
        int idx2;
        int sum;
        
        ELEM(int i, int j, int s) : idx1(i), idx2(j), sum(s) {}
    };
    struct Cmp
    {
        bool operator ()(const ELEM& lhs, const ELEM& rhs) const
        {
            return lhs.sum > rhs.sum;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> ret;
        if (len1 <= 0 || len2 <= 0)
        {
            return ret;
        }
        priority_queue<ELEM, vector<ELEM>, Cmp> pri_que;
        for (int i = 0; i < len1; ++i)
        {
            pri_que.emplace(i, 0, nums1[i] + nums2[0]);
        }
        while (k > 0 && !pri_que.empty())
        {
            ELEM elem = pri_que.top();
            pri_que.pop();
            vector<int> vec = {nums1[elem.idx1], nums2[elem.idx2]};
            ret.emplace_back(vec);
            if (++elem.idx2 < len2)
            {
                pri_que.emplace(elem.idx1, elem.idx2, nums1[elem.idx1] + nums2[elem.idx2]);
            }
            k--;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums1, nums2;
		int k = 0;
		walkString(nums1, line);
		getline(cin, line);
		walkString(nums2, line);
		getline(cin, line);
		walkString(k, line);
		cout << toString(Solution().kSmallestPairs(nums1, nums2, k)) << endl;
	}
	return 0;
}