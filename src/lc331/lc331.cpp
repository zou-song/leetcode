#include "lc.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
        {
            return false;
        }
        int len = preorder.size();
        if (preorder[0] == '#')
        {
            if (len == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        stack<int> stk;
        stk.push(2);
        int idx = 1;
        while (idx < len && isdigit(preorder[idx]))
        {
            idx++;
        }
        while (idx < len)
        {
            char c = preorder[idx];
            if (isdigit(c))
            {
                if (stk.empty())
                {
                    return false;
                }
                stk.push(2);
                int end = idx + 1;
                while (end < len && isdigit(preorder[end]))
                {
                    end++;
                }
                idx = end;
            }
            else if (c == '#')
            {
                if (stk.empty())
                {
                    return false;
                }
                while (!stk.empty() && --stk.top() == 0)
                {
                    stk.pop();
                }
                idx++;
            }
            else
            {
                idx++;
            }
        }
        return stk.empty() ? true : false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string preorder;
		walkString(preorder, line);
		cout << toString(Solution().isValidSerialization(preorder)) << endl;
	}
	return 0;
}