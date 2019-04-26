#include "lc.h"

class Solution {
    struct Coeff
    {//ax + by + c = 0;
        int a;
        int b;
        int c;
    };
    struct Hasher
    {
        size_t operator()(const Coeff& c) const
        {
            return hash<int>()(c.a) ^ hash<int>()(c.b) ^ hash<int>()(c.c);
        }
    };
    struct Equaller
    {
        bool operator()(const Coeff& c1, const Coeff& c2) const
        {
            bool b1 = ((c1.a * c2.b) == (c1.b * c2.a));
            bool b2 = ((c1.a * c2.c) == (c1.c * c2.a));
            bool b3 = ((c1.b * c2.c) == (c1.c * c2.b));
            return b1 && b2 && b3;
        }
    };
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        unordered_map<Coeff, int, Hasher, Equaller> hashmap;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                Coeff c;
                c.a = points[i][1] - points[j][1];
                c.b = points[j][0] - points[i][0];
                c.c = points[i][0] * points[j][1] - points[j][0] * points[i][1];
                hashmap[c]++;
            }
        }
        auto iter = max_element(hashmap.begin(), hashmap.end(), [](const pair<Coeff, int>& lhs, const pair<Coeff, int>& rhs){
            return lhs.second < rhs.second;
        });
        return iter->second;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<int>> points;
		walkString(points, line);
		cout << toString(Solution().maxPoints(points)) << endl;
	}
	return 0;
}