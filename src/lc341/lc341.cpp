#include "lc.h"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
	vector<NestedInteger> _tmp;
public:
	bool isInteger() const { return true; }
	int getInteger() const { return 0; }
	const vector<NestedInteger>& getList() const { return _tmp; }
};

class NestedIterator {
    typedef vector<NestedInteger>::const_iterator Iterator;
    struct IterElem
    {
        Iterator _iter;
        Iterator _end;
        IterElem* _parent;
        IterElem() : _parent(NULL){}
        
        IterElem& operator ++()
        {
            ++_iter;
            locateInteger();
            return *this;
        }
        
        void locateInteger()
        {
            while (true)
            {
                if (_iter == _end)
                {
                    if (!_parent)
                    {
                        break;
                    }
                    _iter = _parent->_iter;
                    _end = _parent->_end;
                    _parent = _parent->_parent;
                    ++_iter;
                }
                else if (_iter->isInteger())
                {
                    break;
                }
                else if (_iter->getList().empty())
                {
                    ++_iter;
                }
                else
                {
                    Iterator beg = _iter->getList().begin();
                    Iterator end = _iter->getList().end();
                    IterElem *p = new IterElem;
                    p->_iter = _iter;
                    p->_end = _end;
                    p->_parent = _parent;
                    _iter = beg;
                    _end = end;
                    _parent = p;
                }
            }
        }
    };
    IterElem* _head;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        _head = new IterElem;
        _head->_iter = nestedList.begin();
        _head->_end = nestedList.end();
        _head->locateInteger();
    }

    int next() {
        int val = _head->_iter->getInteger();
        ++(*_head);
        return val;
    }
    
    bool hasNext() {
        return _head->_iter != _head->_end;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
