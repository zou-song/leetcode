#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        for (int i = 1; i < n && p; ++i)
        {
            p = p->next;
        }
        if (!p) return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (p->next)
        {
            pre = cur;
            cur = cur->next;
            p = p->next;
        }
        if (pre)
        {
            pre->next = cur->next;
            delete cur;
            return head;
        }
        head = cur->next;
        delete cur;
        return head;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		getline(cin, line);
		int n = 0;
		walkString(n, line);
		lclist.head = Solution().removeNthFromEnd(lclist.head, n);
		cout << toString(lclist) << endl;
	}
	return 0;
}