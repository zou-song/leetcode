#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		cout << toString(Solution().maxDepth(btree.root)) << endl;
	}
	return 0;
}