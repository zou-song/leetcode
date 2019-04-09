#include "lc.h"

typedef LCListNode<int> ListNode;
typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* beg, ListNode* end)
    {
        if (beg == end)
            return NULL;
        ListNode *p1 = beg, *p2 = beg;
        while (p2 != end && p2->next != end && p2->next->next != end)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        TreeNode *pnode = new TreeNode(p1->val);
        pnode->left = sortedListToBST(beg, p1);
        pnode->right = sortedListToBST(p1->next, end);
        return pnode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCList<int> lclist;
		walkString(lclist, line);
		LCBinaryTree<int> btree;
		btree.root = Solution().sortedListToBST(lclist.head);
		cout << toString(btree) << endl;
	}
	return 0;
}