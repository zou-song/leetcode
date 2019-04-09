#include "lc.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        int len = input.size();
        int idx = 0;
        while (idx < len)
        {
            if (input[idx] == '+' || input[idx] == '-' || input[idx] == '*')
                ops.push_back(input[idx++]);
            else if (isdigit(input[idx]))
            {
                int end = idx + 1;
                while (end < len && isdigit(input[end]))
                    end++;
                nums.push_back(stoi(input.substr(idx, end - idx)));
                idx = end;
            }
            else
                idx++;
        }
        int numsize = nums.size();
        vector<vector<vector<int>>> dp(numsize);
        for_each(dp.begin(), dp.end(), [numsize](vector<vector<int>> &vec){
            vec.resize(numsize);
        });
        for (int i = 0; i < numsize; ++i)
        {
            dp[i][i].push_back(nums[i]);
            for (int j = i - 1; j >= 0; --j)
            {
                for (int k = j; k < i; ++k)
                {
                    for (int n1 : dp[j][k])
                        for (int n2 : dp[k + 1][i])
                            switch (ops[k])
                            {
                                case '+':
                                    dp[j][i].push_back(n1 + n2);
                                    break;
                                case '-':
                                    dp[j][i].push_back(n1 - n2);
                                    break;
                                case '*':
                                    dp[j][i].push_back(n1 * n2);
                                    break;
                            }
                }
            }
        }
        return dp[0][numsize - 1];
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string input;
		walkString(input, line);
		cout << toString(Solution().diffWaysToCompute(input)) << endl;
	}
	return 0;
}