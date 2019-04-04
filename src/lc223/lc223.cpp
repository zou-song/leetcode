#include "lc.h"

class Solution {
    typedef pair<int, int> POINT;
    typedef pair<POINT, POINT> RECT;
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        POINT p1(A, B);
        POINT p2(C, D);
        RECT r1(p1, p2);
        POINT p3(E, F);
        POINT p4(G, H);
        RECT r2(p3, p4);
        int sub = 0;
        int x1 = max(r1.first.first, r2.first.first);
        int x2 = min(r1.second.first, r2.second.first);
        int y1 = max(r1.first.second, r2.first.second);
        int y2 = min(r1.second.second, r2.second.second);
        if (x2 > x1 && y2 > y1) sub = (x2 - x1) * (y2 - y1);
        return (p2.first - p1.first) * (p2.second - p1.second) - sub + (p4.first - p3.first) * (p4.second - p3.second);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{	
		int A = 0;
		walkString(A, line);
		getline(cin, line);
		int B = 0;
		walkString(B, line);
		getline(cin, line);
		int C = 0;
		walkString(C, line);
		getline(cin, line);
		int D = 0;
		walkString(D, line);
		getline(cin, line);
		int E = 0;
		walkString(E, line);
		getline(cin, line);
		int F = 0;
		walkString(F, line);
		getline(cin, line);
		int G = 0;
		walkString(G, line);
		getline(cin, line);
		int H = 0;
		walkString(H, line);
		cout << toString(Solution().computeArea(A, B, C, D, E, F, G, H)) << endl;
	}
	return 0;
}
