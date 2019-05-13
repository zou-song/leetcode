#include "lc.h"

class SummaryRanges {
    map<int, int> _rbmap;
    typedef map<int, int>::iterator Iterator;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Iterator up_it = _rbmap.upper_bound(val);
        Iterator bf_it;
        if (up_it == _rbmap.begin())
        {
            bf_it = _rbmap.insert(up_it, pair<int, int>(val, val));
        }
        else
        {
            bf_it = up_it;
            --bf_it;
            if (bf_it->second == val - 1)
            {
                bf_it->second = val;
            }
            else if (bf_it->second < val)
            {
                bf_it = _rbmap.insert(up_it, pair<int, int>(val, val));
            }
        }
        if(up_it != _rbmap.end() && bf_it->second == up_it->first - 1)
        {
            bf_it->second = up_it->second;
            _rbmap.erase(up_it);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for (auto &pr : _rbmap)
        {
            vector<int> vec = {pr.first, pr.second};
            ret.emplace_back(vec);
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }