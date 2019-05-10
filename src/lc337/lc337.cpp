#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int func(TreeNode* root, bool parent)
    {
        if (!root)
        {
            return 0;
        }
        int lsum = func(root->left, false);
        int rsum = func(root->right, false);
        if (parent)
        {
            return lsum + rsum;
        }
        int lsum1 = func(root->left, true);
        int rsum1 = func(root->right, true);
        int tmp = lsum1 + rsum1 + root->val;
        return (tmp > (lsum + rsum)) ? tmp : (lsum + rsum);
    }
    int rob(TreeNode* root) {
        return func(root, false);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		cout << toString(Solution().rob(btree.root));
	}
	return 0;
}