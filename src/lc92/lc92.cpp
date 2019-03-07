#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)  return head;
        ListNode *pre = NULL, *beg = head;
        ListNode *end = head, *next = head->next;
        while (m > 1)
        {
            pre = beg;
            beg = beg->next;
            end = beg;
            next = end->next;
            m--;    n--;
        }
        while (n > 1)
        {
            end = end->next;
            next = end->next;
            n--;
        }
        ListNode *tmppre = NULL;
        ListNode *tmpcur = beg;
        while (tmpcur != end)
        {
            ListNode *tmpnext = tmpcur->next;
            tmpcur->next = tmppre;
            tmppre = tmpcur;
            tmpcur = tmpnext;
        }
        end->next = tmppre;
        if (pre)
            pre->next = end;
        else
            head = end;
        beg->next = next;
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
		getline(cin, line);
		int m = 0;
		walkString(m, line);
		getline(cin, line);
		int n = 0;
		walkString(n, line);
		lclist.head = Solution().reverseBetween(lclist.head, m, n);
		cout << toString(lclist) << endl;
	}
	return 0;
}