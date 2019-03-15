#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    bool isBalanced(TreeNode* root, int &height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        bool l = isBalanced(root->left, leftHeight);
        bool r = isBalanced(root->right, rightHeight);
        if (!l || !r)   return false;
        if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1)
            return false;
        height = max(leftHeight, rightHeight) + 1;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		bool output = Solution().isBalanced(btree.root);
		cout << toString(output) << endl;
	}
	return 0;
}