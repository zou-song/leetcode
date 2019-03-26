#include "lc.h"

class MinStack {
    vector<int> mstk;
    vector<int> curmin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        mstk.push_back(x);
        if (curmin.empty())
            curmin.push_back(x);
        else
        {
            if (x < curmin.back())
                curmin.push_back(x);
            else
                curmin.push_back(curmin.back());
        }
    }
    
    void pop() {
        mstk.pop_back();
        curmin.pop_back();
    }
    
    int top() {
        return mstk.back();
    }
    
    int getMin() {
        return curmin.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }