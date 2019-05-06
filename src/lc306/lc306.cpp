#include "lc.h"

class Solution {
public:
    string strAdd(const string &s1, const string& s2)
    {
        int pre_add = 0;
        int len1 = s1.size();
        int len2 = s2.size();
        int i = len1 - 1, j = len2 - 1;
        vector<int> nums;
        while (i >= 0 && j >= 0)
        {
            int v1 = s1[i] - '0';
            int v2 = s2[j] - '0';
            int v = v1 + v2 + pre_add;
            nums.push_back(v % 10);
            pre_add = v / 10;
            i--;    j--;
        }
        while (i >= 0)
        {
            int v1 = s1[i] - '0';
            int v = v1 + pre_add;
            nums.push_back(v % 10);
            pre_add = v / 10;
            i--;
        }
        while (j >= 0)
        {
            int v2 = s2[j] - '0';
            int v = v2 + pre_add;
            nums.push_back(v % 10);
            pre_add = v / 10;
            j--;
        }
        if (pre_add > 0)
        {
            nums.push_back(pre_add);
        }
        string ret;
        for (auto riter = nums.rbegin(); riter != nums.rend(); ++riter)
        {
            ret += ('0' + *riter);
        }
        return ret;
    }
    
    bool isAdditiveNumber(const string& num, int idx, const string& pre1, const string& pre2)
    {
        int len = num.size();
        if (idx >= len)
        {
            return true;
        }
        if (num[idx] == '0')
        {
            if (pre1 != "0" || pre2 != "0")
            {
                return false;
            }
        }
        string add_str = strAdd(pre1, pre2);
        int add_len = add_str.size();
        int i = idx, j = 0;
        while (i < len && j < add_len && num[i] == add_str[j])
        {
            i++;    j++;
        }
        if (j < add_len)
        {
            return false;
        }
        return isAdditiveNumber(num, i, pre2, add_str);
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if (len < 3)
        {
            return false;
        }
        if (num[0] == '0')
        {
            if (num[1] == '0')
            {
                return isAdditiveNumber(num, 2, "0", "0");
            }
            for (int j = 1; j < len - 1; ++j)
            {
                bool ret = isAdditiveNumber(num, j + 1, "0", num.substr(1, j ));
                if (ret)
                {
                    return true;
                }
            }
            return false;
        }
        for (int i = 0; i < len - 2; ++i)
        {
            if (num[i + 1] == '0')
            {
                bool ret = isAdditiveNumber(num, i + 2, num.substr(0, i + 1), "0");
                if (ret)
                {
                    return true;
                }
                continue;
            }
            for (int j = i + 1; j < len - 1; ++j)
            {
                bool ret = isAdditiveNumber(num, j + 1, num.substr(0, i + 1), num.substr(i + 1, j - i));
                if (ret)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string num;
		walkString(num, line);
		cout << toString(Solution().isAdditiveNumber(num)) << endl;
	}
	return 0;
}