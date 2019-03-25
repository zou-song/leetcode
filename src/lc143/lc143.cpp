#include "lc.h"

typedef LCListNode<int> ListNode;

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode *p = head;
        while (p)
        {
            vec.push_back(p);
            p = p->next;
        }
        int idx1 = 0;
        int idx2 = vec.size() - 1;
        ListNode *pre = NULL;
        while (idx1 <= idx2)
        {
            if (idx1 == idx2)
            {
                if (pre)
                    pre->next = vec[idx1];
                vec[idx1]->next = NULL;
            }
            else
            {
                vec[idx1]->next = vec[idx2];
                vec[idx2]->next = NULL;
                if (pre)
                    pre->next = vec[idx1];
                pre = vec[idx2];
            }
            idx1++;
            idx2--;
        }
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> llist;
		walkString(llist, line);
		Solution().reorderList(llist.head);
		cout << toString(llist) << endl;
	}
	return 0;
}