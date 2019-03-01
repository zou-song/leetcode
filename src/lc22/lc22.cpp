class Solution {
public:
    void func(string str, int ln, int rn, int num, vector<string> &vec)
    {
        if (ln == num && rn == num)
        {
            vec.push_back(str);
            return;
        }
        if (rn > ln)
        {
            return;
        }
        if (ln < num)
        {
            func(str + "(", ln + 1, rn, num, vec);
        }
        if (rn < num)
        {
            func(str + ")", ln, rn + 1, num, vec);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int ln = 0, rn = 0;
        func("", ln, rn, n, ret);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int n = 3;
    vector<string> output = Solution().generateParenthesis(n);
    for (auto &str : output)
    {
        cout << str << "\n";
    }
    return 0;
}