#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *pre = NULL, *cur = head;
        while (cur)
        {
            ListNode *next = cur;
            while (next && next->val == cur->val)
                next = next->next;
            if (cur->next == next)
            {
                if (!pre)
                    head = cur;
                else
                    pre->next = cur;
                pre = cur;
                pre->next = NULL;
                cur = next;
            }
            else
            {
                while (cur != next)
                {
                    ListNode *tmp = cur->next;
                    delete cur;
                    cur = tmp;
                }
            }
        }
        if (!pre)
            return NULL;
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