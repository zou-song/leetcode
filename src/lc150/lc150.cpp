#include "lc.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmp;
        for (auto &str : tokens)
        {
            if (str == "+")
            {
                int n2 = tmp.top();
                tmp.pop();
                int n1 = tmp.top();
                tmp.pop();
                int num = n1 + n2;
                tmp.push(num);
            }
            else if (str == "-")
            {
                int n2 = tmp.top();
                tmp.pop();
                int n1 = tmp.top();
                tmp.pop();
                int num = n1 - n2;
                tmp.push(num);
            }
            else if (str == "*")
            {
                int n2 = tmp.top();
                tmp.pop();
                int n1 = tmp.top();
                tmp.pop();
                int num = n1 * n2;
                tmp.push(num);
            }
            else if (str == "/")
            {
                int n2 = tmp.top();
                tmp.pop();
                int n1 = tmp.top();
                tmp.pop();
                int num = n1 / n2;
                tmp.push(num);
            }
            else
            {
                tmp.push(stoi(str));
            }
        }
        return tmp.top();
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<string> tokens;
		walkString(tokens, line);
		cout << toString(Solution().evalRPN(tokens)) << endl;
	}
	return 0;
}