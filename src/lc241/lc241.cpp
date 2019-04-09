#include "lc.h"

class Solution {
public:
    void diffWaysToCompute(list<int>& nums, list<char>& ops, vector<int>& ret)
    {
        if (ops.empty())
        {
            ret.push_back(nums.front());
            return;
        }
        auto niter = nums.begin();
        for (auto oiter = ops.begin(); oiter != ops.end(); ++oiter, ++niter)
        {
            char op = *oiter;
            oiter = ops.erase(oiter);
            int n1 = *niter;
            niter = nums.erase(niter);
            int n2 = *niter;
            niter = nums.erase(niter);
            int n = 0;
            switch (op)
            {
                case '+':
                    n = n1 + n2;
                    break;
                case '-':
                    n = n1 - n2;
                    break;
                case '*':
                    n = n1 * n2;
                    break;
            }
            nums.insert(niter, n);
            diffWaysToCompute(nums, ops, ret);
            oiter = ops.insert(oiter, op);
            niter = nums.erase(niter);
            niter = nums.insert(niter, n2);
            niter = nums.insert(niter, n1);
        }
    }
    vector<int> diffWaysToCompute(string input) {
        list<int> nums;
        list<char> ops;
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
        vector<int> ret;
        diffWaysToCompute(nums, ops, ret);
        return ret;
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