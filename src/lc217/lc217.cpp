#include "lc.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int n : nums)
        {
            if (hashset.count(n))
                return true;
            hashset.insert(n);
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
		cout << toString(Solution().containsDuplicate(nums)) << endl;
	}
	return 0;
}