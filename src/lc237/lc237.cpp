#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node;
        while (p && p->next && p->next->next)
        {
            p->val = p->next->val;
            p = p->next;
        }
        p->val = p->next->val;
        delete p->next;
        p->next = NULL;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		int n = 0;
		getline(cin, line);
		walkString(n, line);
		ListNode *node = lclist.head;
		while (node)
		{
			if (node->val == n)
			{
				break;
			}
			node = node->next;
		}
		Solution().deleteNode(node);
		cout << toString(lclist) << endl;
	}
	return 0;
}