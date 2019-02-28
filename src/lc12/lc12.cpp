#include "lc.h"

class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> int_roman_map = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
        auto beg = int_roman_map.begin();
        auto end = int_roman_map.end();
        string str;
        while (num > 0 && beg != end)
        {
            if (num >= beg->first)
            {
                str += beg->second;
                num -= beg->first;
            }
            else
            {
                ++beg;
            }
        }
        return str;
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
