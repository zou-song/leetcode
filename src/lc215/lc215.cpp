#include "lc.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> tmp;
        for (int n : nums)
        {
            if (tmp.size() < (size_t)k)
            {
                tmp.push_back(n);
                push_heap(tmp.begin(), tmp.end(), [](int lhs, int rhs){
                    return lhs > rhs;
                });
            }
            else if (n > tmp.front())
            {
                pop_heap(tmp.begin(), tmp.end(), [](int lhs, int rhs){
						return lhs > rhs;
				});
                tmp.pop_back();
                tmp.push_back(n);
                push_heap(tmp.begin(), tmp.end(), [](int lhs, int rhs){
                    return lhs > rhs;
                });
            }
        }
        return tmp.front();
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		getline(cin, line);
		int k = 0;
		walkString(k, line);
		cout << toString(Solution().findKthLargest(nums, k)) << endl;
	}
	return 0;
}
