#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return NULL;
        ListNode *ln1 = NULL, *ln2 = NULL;
        ListNode *h1 = NULL, *h2 = NULL;
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                if (!ln1)
                    h1 = cur;
                else
                    ln1 ->next = cur;
                ln1 = cur;
            }
            else
            {
                if (!ln2)
                    h2 = cur;
                else
                    ln2->next = cur;
                ln2 = cur;
            }
            cur = cur->next;
        }
        if (ln1)
            ln1->next = h2;
		if (ln2)
			ln2->next = NULL;
        if (h1)
            return h1;
        return h2;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		getline(cin, line);
		int x = 0;
		walkString(x, line);
		lclist.head = Solution().partition(lclist.head, x);
		cout << toString(lclist) << endl;
	}
	return 0;
}
