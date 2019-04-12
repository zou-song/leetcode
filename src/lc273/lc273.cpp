#include "lc.h"

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)   return "Zero";
        vector<string> words1 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> words2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> words3 = {"Thousand", "Million", "Billion"};
        string ret;
        int idx3 = -1;
        while (num)
        {
            string str;
            int n = num % 1000;
            int n1 = n / 100;
            if (n1 > 0)
                str += (words1[n1] + " Hundred");
            int n2 = n % 100;
            if (n2 == 0)
            {
                if (n1 != 0)
                {
                    if (idx3 >= 0)
                    {
                        if (ret.empty())
                            ret = str + " " + words3[idx3];
                        else    ret = str + " " + words3[idx3] + " " + ret;
                    }
                    else
                        ret = str;
                }
            }
            else
            {
                int n3 = n2 / 10;
                if (n3 >= 2)
                {
                    if (!str.empty())
                        str = str + " ";
                    str = str + words2[n3 - 2];
                    int n4 = n2 % 10;
                    if (n4 > 0)
                        str = str + " " + words1[n4];
                }
                else if (n3 > 0)
                {
                    int n4 = n2 % 100;
                    if (!str.empty())
                        str = str + " ";
                    str = str + words1[n4];
                }
                else
                {
                    int n4 = n2 % 10;
                    if (!str.empty())
                        str = str + " ";
                    str = str + words1[n4];
                }
                if (idx3 >= 0)
                {
                    if (ret.empty())
                        ret = str + " " + words3[idx3];
                    else
                        ret = str + " " + words3[idx3] + " " + ret;
                }
                else
                    ret = str;
            }
            num /= 1000;
            idx3++;
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
		cout << toString(Solution().numberToWords(num)) << endl;
	}
	return 0;
}