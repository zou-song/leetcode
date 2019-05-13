#include "lc.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            if (nums1[idx1] == nums2[idx2])
            {
                ret.push_back(nums1[idx1]);
                idx1++; idx2++;
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
		getline(cin, line);
		vector<int> nums2;
		walkString(nums2, line);
		cout << toString(Solution().intersect(nums1, nums2)) << endl;
	}
	return 0;
}