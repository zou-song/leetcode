#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *p = head;
        while (p)
        {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        if (pre)
            head = pre;
        return head;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		lclist.head = Solution().reverseList(lclist.head);
		cout << toString(lclist) << endl;
	}
	return 0;
}