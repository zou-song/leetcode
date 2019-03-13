#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int len = lists.size();
        vector<ListNode*> tmp;
        for (auto &p : lists)
        {
            if (p)  tmp.push_back(p);
        }
        ListNode *head = NULL, *pre = NULL;
        auto iter1 = tmp.begin();
        auto iter2 = tmp.end();
        while (iter1 != iter2)
        {
            sort(iter1, iter2, [](const ListNode* lhs, const ListNode* rhs){
                return lhs->val < rhs->val;
            });
            if (!head)
                head = *iter1;
            if (pre)
                pre->next = *iter1;
            pre = *iter1;
            *iter1 = (*iter1)->next;
            if (*iter1 == NULL)
                ++iter1;
        }
        return head;
    }
    
    //归并
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int idx1, int idx2)
    {
        if (idx1 == idx2)
            return lists[idx1];
        if (idx1 > idx2)
            return NULL;
        int mid = (idx1 + idx2) / 2;
        ListNode *l1 = mergeKLists(lists, idx1, mid);
        ListNode *l2 = mergeKLists(lists, mid + 1, idx2);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        return mergeKLists(lists, 0, len - 1);
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<LCList<int>> listvec;
		walkString(listvec, line);
		vector<ListNode*> lists;
		for (size_t i = 0; i < listvec.size(); ++i)
		{
			lists.push_back(NULL);
			swap(listvec[i].head, lists[i]);
		}
		LCList<int> output;
		output.head = Solution().mergeKLists(lists);
		cout << toString(output) << endl;
	}
	return 0;
}