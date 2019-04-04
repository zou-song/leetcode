#include "lc.h"

class Solution {
public:
    int cal(int num1, int num2, char op)
    {
        switch (op)
        {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
        }
        return 0;
    }
    int calculate(string s) {
        stack<int> numstk;
        stack<char> opstk;
        int len = s.size();
        int idx = 0;
        while (idx < len)
        {
            if (s[idx] == ' ')  idx++;
            else if (isdigit(s[idx]))
            {
                int endidx = idx;
                while (endidx < len && isdigit(s[endidx]))
                    endidx++;
                int num = stoi(s.substr(idx, endidx - idx));
                if (opstk.empty() || (opstk.top() != '+' && opstk.top() != '-'))
                {
                    numstk.push(num);
                }
                else
                {
                    char op = opstk.top();
                    opstk.pop();
                    int num1 = numstk.top();
                    numstk.pop();
                    numstk.push(cal(num1, num, op));
                }
                idx = endidx;
            }
            else if (s[idx] == ')')
            {
                opstk.pop();
                if (!opstk.empty())
                {
                    int num2 = numstk.top();
                    numstk.pop();
                    int num1 = numstk.top();
                    numstk.pop();
                    numstk.push(cal(num1, num2, opstk.top()));
                    opstk.pop();
                }
                idx++;
            }
            else
            {
                opstk.push(s[idx++]);
            }
        }
        if (!numstk.empty())
            return numstk.top();
        return 0;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		cout << toString(Solution().calculate(s)) << endl;
	}
	return 0;
}