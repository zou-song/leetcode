#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder, int lidx1, int ridx1, const vector<int>& inorder, int lidx2, int ridx2)
    {
        if (ridx1 - lidx1 != ridx2 - lidx2)
            return NULL;
        if (ridx1 < lidx1)  return NULL;
        int i = lidx2;
        while (i <= ridx2 && inorder[i] != preorder[lidx1])
            i++;
        TreeNode *root = new TreeNode(preorder[lidx1]);
        root->left = buildTree(preorder, lidx1 + 1, i - lidx2 + lidx1, inorder, lidx2, i - 1);
        root->right = buildTree(preorder, i - lidx2 + lidx1 + 1, ridx1, inorder, i + 1, ridx2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size();
        int len2 = inorder.size();
        return buildTree(preorder, 0, len1 - 1, inorder, 0, len2 - 1);
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		vector<int> preorder, inorder;
		walkString(preorder, line);
		getline(cin, line);
		walkString(inorder, line);
		LCBinaryTree<int> btree;
		btree.root = Solution().buildTree(preorder, inorder);
		cout << toString(btree) << endl;
	}
	return 0;
}