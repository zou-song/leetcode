#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)  return NULL;
		if (!head->next)	return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while (p1 && p2 && p1 != p2)
        {
            p1 = p1->next;
            if (p2->next)
                p2 = p2->next->next;
            else
                p2 = NULL;
        }
        if (!p1 || !p2 || p1 != p2)
            return NULL;
        int circle_len = 1;
        p1 = p1->next;
        while (p1 != p2)
        {
            p1 = p1->next;
            circle_len++;
        }
        p1 = head;
        p2 = head;
        for (int i = 1; i < circle_len; ++i)
            p2 = p2->next;
        while (p2->next != p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCCircledList<int> clist;
		walkString(clist, line);
		getline(cin, line);
		int pos = 0;
		walkString(pos, line);
		clist.setCircledPos(pos);
		LCListNode<int> *node = Solution().detectCycle(clist.head);
		if (!node)	cout << "NULL" << endl;
		else	cout << toString(node->val) << endl;
	}
	return 0;
}
