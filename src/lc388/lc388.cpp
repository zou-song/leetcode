#include "lc.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        int ret = 0;
        stack<int> stk;
        int len = input.size();
        int idx = 0;
        int tab_num = 0;
        while (idx < len)
        {
            if (input[idx] == '\n')
            {
                idx++;
                tab_num = 0;
            }
            else if (input[idx] == '\t')
            {
                int end = idx + 1;
                while (end < len && input[end] == '\t')
                {
                    end++;
                }
                tab_num = end - idx;
                idx = end;
            }
            else
            {
                int end = idx + 1;
                bool is_file = false;
                while (end < len && input[end] != '\n')
                {
                    if (input[end++] == '.')
                    {
                        is_file = true;
                    }
                }
                int sub_len = end - idx;
                while (stk.size() > (size_t)tab_num)
                {
                    stk.pop();
                }
                if (stk.empty())
                {
                    if (is_file && sub_len > ret)
                    {
                        ret = sub_len;
                    }
                    stk.push(sub_len);
                }
                else
                {
                    if (is_file && stk.top() + 1 + sub_len > ret)
                    {
                        ret = stk.top() + 1 + sub_len;
                    }
                    stk.push(stk.top() + 1 + sub_len);
                }
                idx = end;
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
		string input;
		walkString(input, line);
		cout << toString(Solution().lengthLongestPath(input)) << endl;
	}
	return 0;
}