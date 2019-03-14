#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* buildTree(const vector<int>& inorder, int lidx1, int ridx1, const vector<int>& postorder, int lidx2, int ridx2)
    {
        if (ridx1 - lidx1 != ridx2 - lidx2) return NULL;
        if (ridx1 < lidx1)  return NULL;
        int num = postorder[ridx2];
        int i = lidx1;
        while (i <= ridx1 && inorder[i] != num)
            i++;
        if (i > ridx1)  return NULL;
        TreeNode* root = new TreeNode(num);
        root->left = buildTree(inorder, lidx1, i - 1, postorder, lidx2, lidx2 + i - lidx1 - 1);
        root->right = buildTree(inorder, i + 1, ridx1, postorder, lidx2 + i - lidx1, ridx2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len1 = inorder.size();
        int len2 = postorder.size();
        return buildTree(inorder, 0, len1 - 1, postorder, 0, len2 - 1);
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> inorder, postorder;
        walkString(inorder, line);
        getline(cin, line);
        walkString(postorder, line);
        LCBinaryTree<int> btree;
        btree.root = Solution().buildTree(inorder, postorder);
        cout << toString(btree) << endl;
    }
    return 0;
}