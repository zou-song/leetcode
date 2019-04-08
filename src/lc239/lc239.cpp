#include "lc.h"

class Solution {
    template<typename T>
    class MaxStack{
        stack<T> _elem_stk;
        stack<T> _max_stk;
    public:
        void push(const T& t)
        {
            _elem_stk.push(t);
            if (_max_stk.empty())
            {
                _max_stk.push(t);
            }
            else if (t > _max_stk.top())
            {
                _max_stk.push(t);
            }
            else
            {
                _max_stk.push(_max_stk.top());
            }
        }
        
        void pop()
        {
            _elem_stk.pop();
            _max_stk.pop();
        }
        
        const T& top() const
        {
            return _elem_stk.top();
        }
        
        bool empty() const
        {
            return _elem_stk.empty();
        }
        
        T peekMax() const
        {
            return _max_stk.top();
        }
    };
    
    class MaxQueue{
        MaxStack<int> _push_stk;
        MaxStack<int> _pop_stk;
    public:
        void push(int n)
        {
            _push_stk.push(n);
        }
        
        void pop()
        {
            if (!_pop_stk.empty())
                _pop_stk.pop();
            else
            {
                while (!_push_stk.empty())
                {
                    _pop_stk.push(_push_stk.top());
                    _push_stk.pop();
                }
                _pop_stk.pop();
            }
        }
        
        bool empty() const
        {
            return _push_stk.empty() && _pop_stk.empty();
        }
        
        int peekMax() const
        {
            int n1 = INT_MIN, n2 = INT_MIN;
            if (!_push_stk.empty())
                n1 = _push_stk.peekMax();
            if (!_pop_stk.empty())
                n2 = _pop_stk.peekMax();
            return max(n1, n2);
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int len = nums.size();
        MaxQueue mque;
        for (int i = 0; i < len && i < k; ++i)
        {
            mque.push(nums[i]);
        }
        if (!mque.empty())
            ret.push_back(mque.peekMax());
        for (int i = k; i < len; ++i)
        {
            mque.pop();
            mque.push(nums[i]);
            ret.push_back(mque.peekMax());
        }
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
		cout << toString(maxSlidingWindow(nums, k)) << endl;
	}
	return 0;
}