#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *pre = head, *cur = head->next;
        while (cur)
        {
            if (cur->val == pre->val)
            {
                ListNode *tmp = cur->next;
                delete cur;
                pre->next = tmp;
                cur = tmp;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		lclist.head = Solution().deleteDuplicates(lclist.head);
		cout << toString(lclist) << endl;
	}
	return 0;
}