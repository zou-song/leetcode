#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    bool isValidBST(TreeNode* root, long long lb, long long ub)
    {
        if (!root)  return true;
        if (root->val <= lb || root->val >= ub) return false;
        return isValidBST(root->left, lb, root->val) && isValidBST(root->right, root->val, ub);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> input;
		walkString(input, line);
		bool output = Solution().isValidBST(input.root);
		cout << toString(output) << endl;
	}
	return 0;
}