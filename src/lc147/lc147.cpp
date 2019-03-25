#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *new_head = head;
        ListNode *p = head;
        ListNode *p_pre = NULL;
        while (p)
        {
            ListNode *pre = NULL;
            ListNode *ist = new_head;
            while (ist != p && p->val >= ist->val)
            {
                pre = ist;
                ist = ist->next;
            }
            if (ist == p)
            {
                p_pre = p;
                p = p->next;
            }
            else
            {
                ListNode *new_p = p->next;
                if (p_pre)
                    p_pre->next = new_p;
                p->next = ist;
                if (pre)
                    pre->next = p;
                else
                    new_head = p;
                p = new_p;
            }
        }
        return new_head;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while(getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		lclist.head = Solution().insertionSortList(lclist.head);
		cout << toString(lclist) << endl;
	}
	return 0;
}