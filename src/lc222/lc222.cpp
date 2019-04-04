#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)  return 0;
        list<TreeNode*> que;
        que.push_back(root);
        int ret = 0;
        while (!que.empty())
        {
            TreeNode *p = que.front();
            que.pop_front();
            ret++;
            if (p->left)
                que.push_back(p->left);
            if (p->right)
                que.push_back(p->right);
        }
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
		cout << toString(Solution().countNodes(btree.root)) << endl;
	}
	return 0;
}