#include "lc.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n -1;
        int idx = m + n - 1;
        while (idx1 >= 0 && idx2 >= 0)
        {
            if (nums1[idx1] < nums2[idx2])
                nums1[idx--] = nums2[idx2--];
            else
                nums1[idx--] = nums1[idx1--];
        }
        while (idx2 >= 0)
            nums1[idx--] = nums2[idx2--];
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        Solution().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}