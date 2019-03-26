#include "lc.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int idx1 = 0, idx2 = len - 1;
        while (idx1 < idx2)
        {
            if (numbers[idx1] + numbers[idx2] == target)
                return {idx1 + 1, idx2 + 1};
            else if (numbers[idx1] + numbers[idx2] < target)
                idx1++;
            else
                idx2--;
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> numbers;
		walkString(numbers, line);
		getline(cin, line);
		int target = 0;
		walkString(target, line);
		cout << toString(Solution().twoSum(numbers, target)) << endl;
	}
	return 0;
}