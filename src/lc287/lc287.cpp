#include "lc.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)   return 0;
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2)
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		cout << toString(Solution().findDuplicate(nums)) << endl;
	}
	return 0;
}