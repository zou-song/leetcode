#include "lc.h"


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    vector<NestedInteger*> _pool;
public:
    ~Solution()
    {
        for_each(_pool.begin(), _pool.end(),[](NestedInteger* p){
            delete p;
        });
    }
    NestedInteger deserialize(string s) {
        stack<NestedInteger*> stk;
        int len = s.size();
        int idx = 0;
        NestedInteger* root = NULL;
        while (idx < len)
        {
            if(s[idx] == '[')
            {
                NestedInteger *p = new NestedInteger;
                stk.push(p);
                _pool.push_back(p);
                idx++;
            }
            else if (s[idx] == ']')
            {
                NestedInteger *p = stk.top();
                stk.pop();
                if (stk.empty())
                {
                    root = p;
                }
                else
                {
                    stk.top()->add(*p);
                }
                idx++;
            }
            else if (s[idx] == '-' || isdigit(s[idx]))
            {
                int i = idx + 1;
                while (i < len && isdigit(s[i]))
                {
                    i++;
                }
                int val = stoi(s.substr(idx, i - idx));
                if (stk.empty())
                {
                    root = new NestedInteger;
                    stk.push(root);
                    _pool.push_back(root);
                    root->setInteger(val);
                }
                else
                {
                    stk.top()->add(val);
                }
                idx = i;
            }
            else
            {
                idx++;
            }
        }
        return *root;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
