#include "lc.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            auto iter = hashmap.find(nums[i]);
            if (iter == hashmap.end())
            {
                hashmap[nums[i]] = i;
            }
            else
            {
                if (i - iter->second <= k)
                    return true;
                iter->second = i;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		int k = 0;
		getline(cin, line);
		walkString(k, line);
		cout << toString(Solution().containsNearbyDuplicate(nums, k)) << endl;
	}
	return 0;
}