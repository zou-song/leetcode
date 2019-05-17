#include "lc.h"

class Solution {
    #define ISONEBYTE(n) ((n & 0x80) == 0)
    #define ISTWOBYTE(n) ((n & 0xe0) == 0xc0)
    #define ISTHREEBYTE(n) ((n & 0xf0) == 0xe0)
    #define ISFOURBYTE(n) ((n & 0xf8) == 0xf0)
    #define ISFOLLOWEDVALID(n) ((n & 0xc0) == 0x80)
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int idx = 0;
        while (idx < len)
        {
            unsigned char n = data[idx];
            if (ISONEBYTE(n))
            {
                idx++;
            }
            else if (ISTWOBYTE(n))
            {
                if (++idx >= len)
                {
                    return false;
                }
                unsigned char n1 = data[idx++];
                if (!ISFOLLOWEDVALID(n1))
                {
                    return false;
                }
            }
            else if (ISTHREEBYTE(n))
            {
                for (int i = 0; i < 2; ++i)
                {
                    if (++idx >= len)
                    {
                        return false;
                    }
                    unsigned char n1 = data[idx];
                    if (!ISFOLLOWEDVALID(n1))
                    {
                        return false;
                    }
                }
                idx++;
            }
            else if (ISFOURBYTE(n))
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (++idx >= len)
                    {
                        return false;
                    }
                    unsigned char n1 = data[idx];
                    if (!ISFOLLOWEDVALID(n1))
                    {
                        return false;
                    }
                }
                idx++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> data;
		walkString(data, line);
		cout << toString(Solution().validUtf8(data)) << endl;
	}
	return 0;
}