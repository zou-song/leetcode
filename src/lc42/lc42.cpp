#include "lc.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int len = height.size();
        vector<int> ldp(len), rdp(len);
        ldp[0] = height[0];
        for (int i = 1; i < len; ++i)
        {
            ldp[i] = max(ldp[i - 1], height[i]);
        }
        rdp[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i)
        {
            rdp[i] = max(rdp[i + 1], height[i]);
        }
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            int h = min(ldp[i], rdp[i]);
            if (h > height[i])
                ret += (h - height[i]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> height;
		walkString(height, line);
		cout << toString(Solution().trap(height)) << endl;
	}
	return 0;
}