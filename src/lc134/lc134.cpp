#include "lc.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int idx = 0;
        int pre_sum = 0;
        while (idx < len)
        {
            int cur_sum = 0;
            int i = idx;
            while (i < len && cur_sum >= 0)
            {
                cur_sum = cur_sum + gas[i] - cost[i];
                i++;
            }
            if (i == len && cur_sum + pre_sum >= 0)
                return idx;
            pre_sum += cur_sum;
            idx = i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		std::vector<int> gas, cost;
		walkString(gas, line);
		getline(cin, line);
		walkString(cost, line);
		cout << toString(Solution().canCompleteCircuit(gas, cost)) << endl;
	}
	return 0;
}