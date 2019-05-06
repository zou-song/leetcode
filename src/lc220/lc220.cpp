#include "lc.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (len <= 0)   return false;
        if (k <= 0 || t < 0) return false;
        unordered_map<long long, long long> hashmap;
        for (int i = 0; i < len; ++i)
        {
            long long n = (long long)nums[i] - INT_MIN;
            long long idx = n / ((long long)t + 1);
            if (hashmap.find(idx) != hashmap.end())
            {
                return true;
            }
            auto iter1 = hashmap.find(idx - 1);
            if (iter1 != hashmap.end() && n - iter1->second <= t)
            {
                return true;
            }
            auto iter2 = hashmap.find(idx + 1);
            if (iter2 != hashmap.end() && iter2->second - n <= t)
            {
                return true;
            }
            if (hashmap.size() >= (size_t)k)
            {
                long long rmidx = ((long long)nums[i - k] - INT_MIN) / ((long long)t + 1);
                hashmap.erase(rmidx);
            }
			hashmap[idx] = n;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        walkString(nums, line);
        int k = 0, t = 0;
        getline(cin, line);
        walkString(k, line);
        getline(cin, line);
        walkString(t, line);
        cout << toString(Solution().containsNearbyAlmostDuplicate(nums, k, t)) << endl;
    }
    return 0;
}
