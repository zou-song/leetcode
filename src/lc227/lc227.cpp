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
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return 0;
    }
    int calculate(string s) {
        int len = s.size();
        if (len <= 0)   return 0;
        int idx = 0;
        stack<int> numstk;
        stack<char> opstk;
        while (idx < len)
        {
            if (s[idx] == ' ')  idx++;
            else if (isdigit(s[idx]))
            {
                int endidx = idx + 1;
                while (endidx < len && isdigit(s[endidx]))
                    endidx++;
                int num = stoi(s.substr(idx, endidx - idx));
                if (opstk.empty() || (opstk.top() != '*' && opstk.top() != '/'))
                {
                    numstk.push(num);
                }
                else
                {
                    int num1 = numstk.top();
                    numstk.pop();
                    char op = opstk.top();
                    opstk.pop();
                    numstk.push(cal(num1, num, op));
                }
                idx = endidx;
            }
            else if (s[idx] == '+' || s[idx] == '-')
            {
                if (!opstk.empty())
                {
                    int num2 = numstk.top();
                    numstk.pop();
                    int num1 = numstk.top();
                    numstk.pop();
                    char op = opstk.top();
                    opstk.pop();
                    numstk.push(cal(num1, num2, op));
                }
                opstk.push(s[idx++]);
            }
            else
            {
                opstk.push(s[idx++]);
            }
        }
        while (!opstk.empty())
        {
            int num2 = numstk.top();
            numstk.pop();
            int num1 = numstk.top();
            numstk.pop();
            char op = opstk.top();
            opstk.pop();
            numstk.push(cal(num1, num2, op));
        }
        return numstk.top();
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