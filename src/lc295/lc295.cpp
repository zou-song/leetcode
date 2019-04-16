#include "lc.h"

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> _max_heap;
    priority_queue<int, vector<int>, greater<int>> _min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (_max_heap.empty())
            _max_heap.push(num);
        else
        {
            int lsz = _max_heap.size();
            int rsz = _min_heap.size();
            if (num > _max_heap.top())
            {
                _min_heap.push(num);
                if (rsz > lsz)
                {
                    _max_heap.push(_min_heap.top());
                    _min_heap.pop();
                }
            }
            else
            {
                _max_heap.push(num);
                if (lsz > rsz)
                {
                    _min_heap.push(_max_heap.top());
                    _max_heap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        int lsz = _max_heap.size();
        int rsz = _min_heap.size();
        if (lsz == rsz)
        {
            double ret = _max_heap.top() + _min_heap.top();
            return ret /= 2.0;
        }
        else if (lsz > rsz)
            return _max_heap.top();
        return _min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }