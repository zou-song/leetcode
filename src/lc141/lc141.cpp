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

template<typename T>
void formCircleList(LCList<T> &llist, int pos)
{
	if (pos < 0)	return;
	LCListNode<T> *p = llist.head;
	LCListNode<T> *tail = llist.head;
	int idx = 0;
	while (idx < pos && tail)
	{
		p = p->next;
		tail = tail->next;
		idx++;
	}
	if (!tail)	return;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = p;
}

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> llist;
		walkString(llist, line);
		getline(cin, line);
		int pos;
		walkString(pos, line);
		formCircleList(llist, pos);
		cout << toString(Solution().hasCycle(llist.head)) << endl;
	}
	return 0;
}