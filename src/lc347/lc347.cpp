#include "lc.h"

class Solution {
    typedef pair<int, int> ELEM;
    struct cmp
    {
        bool operator()(const ELEM& lhs, const ELEM& rhs) const
        {
            return lhs.second > rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int n : nums)
        {
            hashmap[n]++;
        }
        priority_queue<ELEM, vector<ELEM>, cmp> pri_que;
        for (auto iter = hashmap.begin(); iter != hashmap.end(); ++iter)
        {
            if (pri_que.size() < (size_t)k)
            {
                pri_que.push(*iter);
            }
            else if (cmp()(*iter, pri_que.top()))
            {
                pri_que.pop();
                pri_que.push(*iter);
            }
        }
        vector<int> ret;
        while (!pri_que.empty())
        {
            ret.push_back(pri_que.top().first);
            pri_que.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		int k = 0;
		getline(cin, line);
		walkString(k, line);
		cout << toString(Solution().topKFrequent(nums, k)) << endl;
	}
	return 0;
}
