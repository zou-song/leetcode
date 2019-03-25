#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)  return false;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p1 && p2)
        {
            if (p1 == p2)   return true;
            p1 = p1->next;
            if (!p2->next)  return false;
            p2 = p2->next->next;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCCircledList<int> clist;
		walkString(clist, line);
		getline(cin, line);
		int pos;
		walkString(pos, line);
		clist.setCircledPos(pos);
		cout << toString(Solution().hasCycle(clist.head)) << endl;
	}
	return 0;
}
