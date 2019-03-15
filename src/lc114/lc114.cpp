#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)  return;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while (p || !stk.empty())
        {
            if (p || !stk.empty())
            {
                if (p)
                {
                    if (p->right)
                        stk.push(p->right);
                    if (pre)
                    {
                        pre->left = NULL;
                        pre->right = p;
                    }
                    pre = p;
                    p = p->left;
                }
                else
                {
                    p = stk.top();
                    stk.pop();
                }
            }
        }
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		Solution().flatten(btree.root);
		cout << toString(btree) << endl;
	}
	return 0;
}