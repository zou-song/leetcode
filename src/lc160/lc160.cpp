#include "lc.h"

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
 
struct TailNodeKeeper
{
    ListNode *node;
    TailNodeKeeper(ListNode *p) : node(p) {}
    ~TailNodeKeeper(){
        if (node)
            node->next = NULL;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *p1 = headA;
        while (p1->next)
        {
            p1 = p1->next;
        }
        TailNodeKeeper keeper(p1);
        p1->next = headA;
        if (!headB->next)
            return NULL;
        ListNode *p2 = headB->next->next;
        p1 = headB;
        while (p1 && p2 && p1 != p2)
        {
            p1 = p1->next;
            if (!p2->next)
                return NULL;
            p2 = p2->next->next;
        }
        if (!p1 || !p2 || p1 != p2)
            return NULL;
        int circle_len = 1;
        p1 = p1->next;
        while (p1 != p2)
        {
            p1 = p1->next;
            circle_len++;
        }
        p1 = headB;
        p2 = headB;
        for (int i = 1; i < circle_len; ++i)
            p2 = p2->next;
        while (p2->next != p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}