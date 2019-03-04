#include "lc.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        int len = 0;
        for (ListNode *node = head; node != NULL; node = node->next)
            len++;
        k = k % len;
        if (k == 0)
            return head;
        ListNode *pre = head;
        for (int i = 1; i < len - k; ++i)
        {
            pre = pre->next;
        }
        ListNode *new_head = pre->next;
        pre->next = NULL;
        ListNode *tmp = new_head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = head;
        return new_head;
    }
};