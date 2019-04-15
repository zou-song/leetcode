#include "lc.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
typedef vector<int>::iterator vec_iterator;
class Iterator
{
    vec_iterator _begin;
    vec_iterator _end;
public:
	Iterator(const vector<int>& nums)
	{
		_begin = nums.begin();
		_end = nums.end();
	}
	Iterator(const Iterator& iter)
	{
		_begin = iter._begin;
		_end = iter._end;
	}
	virtual ~Iterator(){}
	// Returns the next element in the iteration.
	int next()
	{
		return *_begin;
	}
	// Returns true if the iteration has more elements.
	bool hasNext() const
	{
		return _begin != _end;
	}
};


class PeekingIterator : public Iterator {
    bool _in_peek;
    int _next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _in_peek = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (_in_peek)
            return _next;
        _next = Iterator::next();
        _in_peek = true;
        return _next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (_in_peek)
        {
            _in_peek = false;
            return _next;
        }
        return Iterator::next();
	}

	bool hasNext() const {
        if (_in_peek)
            return true;
        return Iterator::hasNext();
	}
};