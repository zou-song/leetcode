#include "lc.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {
        queue<pair<int, int>> que;
        int len = stones.size();
        if (len < 2)
        {
            return true;
        }
        if (stones[1] != 1)
        {
            return false;
        }
        que.emplace(1, 1);
        vector<vector<bool>> flags(len);
        for_each(flags.begin(), flags.end(), [len](vector<bool>& vec){
            vec.resize(len);
            fill(vec.begin(), vec.end(), false);
        });
        flags[1][1] = true;
        while (!que.empty())
        {
            int idx = que.front().first;
            if (idx == len - 1)
            {
                return true;
            }
            int pre_step = que.front().second;
            que.pop();
            int i = idx + 1;
            while (i < len && stones[i] <= stones[idx] + pre_step + 1)
            {
                if (stones[i] == stones[idx] + pre_step - 1 && pre_step - 1 < len)
                {
                    if (!flags[i][pre_step - 1])
                    {
                        que.emplace(i, pre_step - 1);
                        flags[i][pre_step - 1] = true;
                    }
                }
                else if (stones[i] == stones[idx] + pre_step && pre_step < len)
                {
                    if (!flags[i][pre_step])
                    {
                        que.emplace(i, pre_step);
                        flags[i][pre_step] = true;
                    }
                }
                else if (stones[i] == stones[idx] + pre_step + 1 && pre_step + 1 < len)
                {
                    if (!flags[i][pre_step + 1])
                    {
                        que.emplace(i, pre_step + 1);
                        flags[i][pre_step + 1] = true;
                    }
                }
                i++;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<int> stones;
		walkString(stones, line);
		cout << toString(Solution().canCross(stones)) << endl;
	}
	return 0;
}