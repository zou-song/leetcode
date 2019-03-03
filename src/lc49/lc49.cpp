#include "lc.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash_map;
        vector<vector<string>> ret;
        for (auto &str : strs)
        {
            string ostr = str;
            sort(ostr.begin(), ostr.end());
            auto iter = hash_map.find(ostr);
            if (iter != hash_map.end())
            {
                ret[iter->second].push_back(str);
            }
            else
            {
                vector<string> vec = {1, str};
                ret.push_back(vec);
                hash_map[ostr] = ret.size() - 1;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	return 0;
}