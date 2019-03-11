#include "lc.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int idx1 = 0, idx2 = len - 1;
        int ret = 0;
        while (idx1 < idx2)
        {
            int h = (height[idx1] < height[idx2]) ? height[idx1] : height[idx2];
            int area = h * (idx2 - idx1);
            if (area > ret)
                ret = area;
            if (height[idx1] < height[idx2])
                idx1++;
            else
                idx2--;
        }
        return ret;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}