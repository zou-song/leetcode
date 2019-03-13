#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *pre = NULL;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                if (!head)
                    head = l1;
                if (pre)
                    pre->next = l1;
                pre = l1;
                l1 = l1->next;
            }
            else
            {
                if (!head)
                    head = l2;
                if (pre)
                    pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        if (l1)
        {
            if (!head)
                head = l1;
            if (pre)
                pre->next = l1;
        }
        if (l2)
        {
            if (!head)
                head = l2;
            if (pre)
                pre->next = l2;
        }
        return head;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
		LCList<int> lclist1;
		walkString(lclist1, line);
        getline(cin, line);
		LCList<int> lclist2;
		walkString(lclist2, line);
        
        lclist1.head = Solution().mergeTwoLists(lclist1.head, lclist2.head);
		lclist2.head = NULL;

        cout << toString(lclist1) << endl;
    }
    return 0;
}
