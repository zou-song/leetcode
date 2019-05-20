#include "lc.h"

class Solution {
public:
    void predictNum(int n, int base_limit, int base, int pre, vector<int>& ans)
    {
        if (n <= 0)
        {
            ans.emplace_back(pre);
            return;
        }
        if (base >= base_limit)
        {
            return;
        }
        predictNum(n, base_limit, base * 2, pre, ans);
        predictNum(n - 1, base_limit, base * 2, pre + base, ans);
    }
    vector<string> predictHour(int n)
    {
        vector<int> nums;
        predictNum(n, 1 << 4, 1, 0, nums);
        vector<string> ret;
        for (int n : nums)
        {
            if (n > 11)
            {
                continue;
            }
            ret.emplace_back(to_string(n));
        }
        return ret;
    }
    
    vector<string> predictMin(int n)
    {
        vector<int> nums;
        predictNum(n, 1 << 6, 1, 0, nums);
        vector<string> ret;
        for (int n : nums)
        {
            if (n >= 60)
            {
                continue;
            }
            string str = to_string(n);
            if (str.size() < 2)
            {
                ret.emplace_back("0" + str);
            }
            else
            {
                ret.emplace_back(str);
            }
        }
        return ret;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int i = 0; i <= 4; ++i)
        {
            int m_num = num - i;
            if (m_num < 0)
            {
                break;
            }
            else if (m_num > 6)
            {
                continue;
            }
            auto hours = predictHour(i);
            auto mins = predictMin(m_num);
            for (auto &h : hours)
            {
                for (auto &m : mins)
                {
                    ret.emplace_back(h + ":" + m);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int num = 0;
		walkString(num, line);
		cout << toString(Solution().readBinaryWatch(num)) << endl;
	}
	return 0;
}