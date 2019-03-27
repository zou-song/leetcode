#include "lc.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto n : nums)
            strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2){
            int len1 = s1.size();
            int len2 = s2.size();
            int idx1 = 0, idx2 = 0;
            while (idx1 < len1 && idx2 < len2)
            {
                if (s1[idx1] > s2[idx2])
                    return true;
                else if (s1[idx1] < s2[idx2])
                    return false;
                else
                {
                    idx1++;
                    idx2++;
                }
            }
            if (idx1 < len1)
            {
                if (s1[idx1] > s1[0])
                    return true;
                return false;
            }
            if (idx2 < len2)
            {
                if (s2[idx2] > s2[0])
                    return false;
            }
            return true;
        });
        string ret;
        for_each(strs.begin(), strs.end(), [&ret](const string& s){
            ret = ret + s;
        });
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
		cout << toString(Solution().largestNumber(nums)) << endl;
	}
	return 0;
}