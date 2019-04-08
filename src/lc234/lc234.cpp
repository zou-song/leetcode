#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)  return true;
        ListNode *pre = NULL, *next = NULL;
        ListNode *p = head, *pp = head;
        while (pp && pp->next && pp->next->next)
        {
            pp = pp->next->next;
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        next = p->next;
        ListNode *pl = NULL, *pr = NULL;
        if (pp->next)
        {
            p->next = pre;
            pl = p;
            pr = next;
        }
        else
        {
            pl = pre;
            pr = next;
        }
        while (pl && pr)
        {
            if (pl->val != pr->val)
                return false;
            pl = pl->next;
            pr = pr->next;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		cout << toString(Solution().isPalindrome(lclist.head)) << endl;
	}
	return 0;
}