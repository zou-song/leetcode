#include "lc.h"

class Solution {
    struct BucketNode
    {
        bool _empty;
        int _nmin, _nmax;
        BucketNode() : _empty(true), _nmin(INT_MAX), _nmax(INT_MIN) {}
    };
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2)    return 0;
        int nmax = *max_element(nums.begin(), nums.end());
        int nmin = *min_element(nums.begin(), nums.end());
        int b = (nmax - nmin) / (len - 1);
        b = (b < 1) ? 1 : b;
        int bkt_num = (nmax - nmin) / b + 1;
        vector<BucketNode> bkt(bkt_num);
        for (int n : nums)
        {
            int idx = (n - nmin) / b;
            bkt[idx]._empty = false;
            bkt[idx]._nmin = min(bkt[idx]._nmin, n);
            bkt[idx]._nmax = max(bkt[idx]._nmax, n);
        }
        int ret = 0;
        BucketNode *pre = NULL;
        for (int i = 0; i < bkt_num; ++i)
        {
            if (bkt[i]._empty)
            {
                continue;
            }
            if (pre)
            {
                if (ret < bkt[i]._nmin - pre->_nmax)
                {
                    ret = bkt[i]._nmin - pre->_nmax;
                }
            }
            pre = &bkt[i];
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().maximumGap(nums)) << endl;
	}
	return 0;
}