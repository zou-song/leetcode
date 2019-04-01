#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = NULL;
        ListNode *p = head;
        while (p)
        {
            if (p->val == val)
            {
                ListNode *next = p->next;
                if (pre)
                    pre->next = next;
                else
                    head = next;
                delete p;
                p = next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
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
		int val = 0;
		getline(cin, line);
		walkString(val, line);
		lclist.head = Solution().removeElements(lclist.head, val);
		cout << toString(lclist) << endl;
	}
	return 0;
}