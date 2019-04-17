#include "lc.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> *vec1 = &nums1, *vec2 = &nums2;
        if (len1 > len2)
        {
            swap(len1, len2);
            swap(vec1, vec2);
        }
        int beg = 0, end = len1;
        while (beg <= end)
        {
            int i = (beg + end) / 2;
            int j = (len1 + len2 + 1) / 2 - i;
            if (i > beg && vec1->at(i - 1) > vec2->at(j))
            {
                end = i - 1;
            }
            else if (i < end && vec2->at(j - 1) > vec1->at(i))
            {
                beg = i + 1;
            }
            else
            {
                double maxLeft = 0;
                if (i <= 0)
                    maxLeft = vec2->at(j - 1);
                else if (j <= 0)
                    maxLeft = vec1->at(i - 1);
                else
                    maxLeft = max(vec1->at(i - 1), vec2->at(j - 1));
                if (1 == (len1 + len2) % 2)
                     return maxLeft;
                double minRight = 0;
                if (i >= len1)
                    minRight = vec2->at(j);
                else if (j >= len2)
                    minRight = vec1->at(i);
                else
                    minRight = min(vec1->at(i), vec2->at(j));
                return (minRight + maxLeft) / 2.0;
            }
        }
        return 0.;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums1, nums2;
		walkString(nums1, line);
		getline(cin, line);
		walkString(nums2, line);
		cout << toString(Solution().findMedianSortedArrays(nums1, nums2)) << endl;
	}
	return 0;
}