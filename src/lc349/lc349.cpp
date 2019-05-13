#include "lc.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        vector<int> ret;
        while (idx1 < len1 && idx2 < len2)
        {
            if (nums1[idx1] == nums2[idx2])
            {
                ret.push_back(nums1[idx1]);
                int end = idx1 + 1;
                while (end < len1 && nums1[end] == nums1[idx1])
                {
                    end++;
                }
                idx1 = end;
                end = idx2 + 1;
                while (end < len2 && nums2[end] == nums2[idx2])
                {
                    end++;
                }
                idx2 = end;
            }
            else if (nums1[idx1] < nums2[idx2])
            {
                idx1++;
            }
            else
            {
                idx2++;
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
		vector<int> nums1;
		walkString(nums1, line);
		vector<int> nums2;
		getline(cin, line);
		walkString(nums2, line);
		cout << toString(Solution().intersection(nums1, nums2)) << endl;
	}
	return 0;
}