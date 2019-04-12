#include "lc.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int beg = 1, end = n;
        while (beg <= end)
        {
            unsigned int mid = (beg + end) / 2;
            if (isBadVersion(mid))
            {
                if (mid == 1 || !isBadVersion(mid - 1))
                    return mid;
                else
                    end = mid - 1;
            }
            else
                beg = mid + 1;
        }
        return end;
    }
};

int BAD_VERSION = 0;
bool isBadVersion(int version)
{
	if (version >= BAD_VERSION)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int version = 0;
		walkString(version, line);
		getline(cin, line);
		walkString(BAD_VERSION, line);
		cout << toString(Solution().firstBadVersion(version)) << endl;
	}
	return 0;
}