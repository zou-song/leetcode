#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
    ListNode *_head;
    int _len;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
        _len = INT_MIN;
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rd = rand();
        if (_len < 0)
        {
            ListNode *p = _head;
            int len = 0;
            while (rd > 0 && p)
            {
                p = p->next;
                len++;
                rd--;
            }
            if (!p)
            {
                _len = len;
            }
            else
            {
                return p->val;
            }
        }
        int idx = rd % _len;
        ListNode *p = _head;
        while (idx > 0 && p)
        {
            p = p->next;
            idx--;
        }
        if (p)
        {
            return p->val;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}