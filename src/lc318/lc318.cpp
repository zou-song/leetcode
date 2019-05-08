#include "lc.h"

class Solution {
    typedef pair<unsigned int, int> ELEM;
public:
    int maxProduct(vector<string>& words) {
        vector<ELEM> vec;
        for (auto &s : words)
        {
            unsigned int bits = 0;
            int len = s.size();
            for_each(s.begin(), s.end(), [&bits](char c){
                bits |= (1 << (c - 'a'));
            });
            vec.emplace_back(bits, len);
        }
        int len = vec.size();
        int ret = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (vec[i].first & vec[j].first == 0)
                {
                    int mul = vec[i].second * vec[j].second;
                    ret = (mul > ret) ? mul : ret;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<string> words;
		walkString(words, line);
		cout << toString(Solution().maxProduct(words)) << endl;
	}
	return 0;
}