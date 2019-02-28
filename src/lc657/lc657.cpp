#include "lc.h"

class Solution {
public:
    bool judgeCircle(string moves) {
        int h_offset = 0, v_offset = 0;
        for (auto c : moves)
        {
            switch (c)
            {
                case 'R':
                    h_offset += 1;
                    break;
                case 'L':
                    h_offset -= 1;
                    break;
                case 'U':
                    v_offset += 1;
                    break;
                case 'D':
                    v_offset -= 1;
                    break;
                default:
                    return false;
            }
        }
        return (h_offset == 0 && v_offset == 0);
    }
};

int main(int argc, char *argv[])
{
    string line;
    while (getline(cin, line)) {
        string moves = stringToString(line);
        
        bool ret = Solution().judgeCircle(moves);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}