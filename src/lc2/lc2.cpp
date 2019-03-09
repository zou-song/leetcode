#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;
        ListNode *p1 = l1, *p2 = l2;
        int add = 0;
        while(p1 && p2)
        {
            int sum = p1->val + p2->val + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode *p = new ListNode(sum);
            if (!head)
                head = p;
            if (tail)
                tail->next = p;
            tail = p;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            int sum = p1->val + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode *p = new ListNode(sum);
            if (!head)
                head = p;
            if (tail)
                tail->next = p;
            tail = p;
            p1 = p1->next;
        }
        while (p2)
        {
            int sum = p2->val + add;
            add = sum / 10;
            sum = sum % 10;
            ListNode *p = new ListNode(sum);
            if (!head)
                head = p;
            if (tail)
                tail->next = p;
            tail = p;
            p2 = p2->next;
        }
        if (add)
        {
            ListNode *p = new ListNode(add);
            if (!head)
                head = p;
            if (tail)
                tail->next = p;
            tail = p;
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> l1, l2;
		walkString(l1, line);
		getline(cin, line);
		walkString(l2, line);
		LCList<int> ret;
		ret.head = Solution().addTwoNumbers(l1.head, l2.head);
		cout << toString(ret) << endl;
	}
	return 0;
}