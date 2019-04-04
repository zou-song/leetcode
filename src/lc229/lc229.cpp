#include "lc.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int len = nums.size();
        int thresh = len / 3;
        vector<int> ret;
        for (int n : nums)
        {
            auto iter = hashmap.find(n);
            if (iter == hashmap.end())
                hashmap[n] = 1;
            else if (iter->second > thresh)
            {
                ret.push_back(n);
                ++(iter->second);
            }
            else
                ++(iter->second);
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
		cout << toString(Solution().majorityElement(nums)) << endl;
	}
	return 0;
}