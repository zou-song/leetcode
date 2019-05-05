#include "lc.h"

class Solution {
    template<typename T, typename Comp>
    struct PeakStack
    {
        stack<T> _elems;
        stack<T> _peak;
        
        void push(const T& v)
        {
            _elems.push(v);
            Comp cmp;
            if (_peak.empty() || cmp(v, _peak.top()))
            {
                _peak.push(v);
            }
            else
            {
                _peak.push(_peak.top());
            }
        }
        
        void pop()
        {
            _elems.pop();
            _peak.pop();
        }
        
        size_t size() const
        {
            return _elems.size();
        }
        
        bool empty() const
        {
            return _elems.empty();
        }
        
        T top() const
        {
            return _elems.top();
        }
        
        T peak() const
        {
            return _peak.top();
        }
    };
    
    template<typename T, typename Comp>
    struct PeakQueue
    {
        PeakStack<T, Comp> _stk1;
        PeakStack<T, Comp> _stk2;
        
        void push(const T& v)
        {
            _stk1.push(v);
        }
        
        void pop()
        {
            if (!_stk2.empty())
            {
                _stk2.pop();
            }
            else
            {
                transferStack();
                _stk1.pop();
            }
        }
        
        size_t size() const
        {
            return _stk1.size() + _stk2.size();
        }
        
        T peak() const
        {
            if (_stk1.empty())
            {
                return _stk2.peak();
            }
            else if(_stk2.empty())
            {
                return _stk1.peak();
            }
            
            T v1 = _stk1.peak();
            T v2 = _stk2.peak();
            
            return Comp()(v1, v2) ? v1 : v2;
        }
        
        void transferStack()
        {
            while (_stk1.size() > 1)
            {
                T v = _stk1.top();
                _stk1.pop();
                _stk2.push(v);
            }
        }
    };
    
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if (len <= 0)   return false;
        PeakQueue<int, greater<int>> max_que;
        PeakQueue<int, less<int>> min_que;
        max_que.push(nums[0]);
        min_que.push(nums[0]);
        for (int i = 1; i < len; ++i)
        {
            while (max_que.size() > (size_t)k)
            {
                max_que.pop();
            }
            while (min_que.size() > (size_t)k)
            {
                min_que.pop();
            }
            long long max_v = max_que.peak();
            long long min_v = min_que.peak();
            long long n = nums[i];
            if (abs(n - max_v) > t || abs(n - min_v) > t)
            {
                return false;
            }
            max_que.push(nums[i]);
            min_que.push(nums[i]);
        }
        return true;
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