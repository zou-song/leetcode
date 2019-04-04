#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		Solution().invertTree(btree.root);
		cout << toString(btree) << endl;
	}
	return 0;
}