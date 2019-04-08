#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int kthSmallest(TreeNode* p, int k, int &ret)
    {
        if (!p) return 0;
        int lnum = kthSmallest(p->left, k, ret);
        if (lnum >= k)  return lnum;
        if (lnum + 1 == k)
        {
            ret = p->val;
            return lnum + 1;
        }
        return lnum + 1 + kthSmallest(p->right, k - lnum - 1, ret);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        if (!root)  return ret;
        int lnum = kthSmallest(root->left, k, ret);
        if (lnum >= k)  return ret;
        if (lnum + 1 == k)  return root->val;
        kthSmallest(root->right, k - lnum - 1, ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		getline(cin, line);
		int k = 0;
		walkString(k, line);
		cout << toString(Solution().kthSmallest(btree.root, k)) << endl;
	}
	return 0;
}