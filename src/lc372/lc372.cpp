#include "lc.h"

class Solution {
public:
    int cal(int a, int b)
    {
        if (b <= 0 || a == 1)
        {
            return 1;
        }
        int c = a % 1337;
        for (int i = 1; i < b; ++i)
        {
            a = (a * c) % 1337;
        }
        return a % 1337;
    }
    int superPow(int a, vector<int>& b) {
        a = a % 1337;
        int len = b.size();
        int pre = cal(a, b[len - 1]);
        int pre2 = a;
        for (int i = len - 2; i >= 0; --i)
        {
            pre2 = cal(pre2, 10);
            if (b[i] != 0)
            {
                int tmp = cal(pre2, b[i]);
                pre = (tmp * pre) % 1337;
            }
        }
        return pre;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int a = 0;
		walkString(a, line);
		vector<int> b;
		getline(cin, line);
		walkString(b, line);
		cout << toString(Solution().superPow(a, b)) << endl;
	}
	return 0;
}