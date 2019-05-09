#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        ListNode *odd_pre = odd_head, *even_pre = even_head;
        
        bool is_odd = true;
        ListNode *p = even_head->next;
        while (p)
        {
            if (is_odd)
            {
                odd_pre->next = p;
                odd_pre = p;
            }
            else
            {
                even_pre->next = p;
                even_pre = p;
            }
            is_odd = !is_odd;
            p = p->next;
        }
        odd_pre->next = even_head;
        even_pre->next = NULL;
        return odd_head;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		lclist.head = Solution().oddEvenList(lclist.head);
		cout << toString(lclist) << endl;
	}
	return 0;
}