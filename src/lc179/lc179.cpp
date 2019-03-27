#include "lc.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto n : nums)
            strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        });
        string ret;
        for_each(strs.begin(), strs.end(), [&ret](const string& s){
            if (ret != "0" || s != "0")
                ret = ret + s;
        });
        return ret.empty() ? "0" : ret;
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