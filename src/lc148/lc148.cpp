#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* halfSort(ListNode* head)
    {
        if (!head || head->next == NULL)  return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *next = slow->next;
        slow->next = NULL;
        ListNode *p1 = halfSort(head);
        ListNode *p2 = halfSort(next);
        ListNode *newbeg = NULL, *pre = NULL;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                if (pre)
                {
                    pre->next = p1;
                }
                if (!newbeg)
                {
                    newbeg = p1;
                }
                pre = p1;
                p1 = p1->next;
            }
            else
            {
                if (pre)
                {
                    pre->next = p2;
                }
                if (!newbeg)
                {
                    newbeg = p2;
                }
                pre = p2;
                p2 = p2->next;
            }
        }
        if (p1)
        {
            if (pre)
            {
                pre->next = p1;
            }
            if (!newbeg)
            {
                newbeg = p1;
            }
        }
        if (p2)
        {
            if (pre)
            {
                pre->next = p2;
            }
            if (!newbeg)
            {
                newbeg = p2;
            }
        }
        return newbeg;
    }
    ListNode* sortList(ListNode* head) {
        return halfSort(head);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		lclist.head = Solution().sortList(lclist.head);
		cout << toString(lclist) << endl;
	}
	return 0;
}