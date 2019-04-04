#include "lc.h"

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        transferQue(true);
        if (!q1.empty())
        {
            int ret = q1.front();
            q1.pop();
            return ret;
        }
        else if (!q2.empty())
        {
            transferQue(false);
            int ret = q2.front();
            q2.pop();
            return ret;
        }
        return INT_MIN;
    }
    
    /** Get the top element. */
    int top() {
        transferQue(true);
        if (!q1.empty())
            return q1.front();
        else if (!q2.empty())
        {
            transferQue(false);
            int ret = q2.front();
            q1.push(ret);
            q2.pop();
            return ret;
        }
        return INT_MIN;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
    
    void transferQue(bool flag)
    {
        queue<int> *que1, *que2;
        if (flag)
        {
            que1 = &q1;
            que2 = &q2;
        }
        else
        {
            que1 = &q2;
            que2 = &q1;
        }
        int len = que1->size();
        for (int i = 0; i < len - 1; ++i)
        {
            que2->push(que1->front());
            que1->pop();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }