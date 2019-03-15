#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ret = 1;
        while (true)
        {
            queue<TreeNode*> tmp;
            while (!que.empty())
            {
                TreeNode* p = que.front();
                que.pop();
                if (!p->left && !p->right)
                    return ret;
                if (p->left)
                    tmp.push(p->left);
                if (p->right)
                    tmp.push(p->right);
            }
            swap(que, tmp);
            if (que.empty())
                break;
            ret++;
        }
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		cout << toString(Solution().minDepth(btree.root)) << endl;
	}
	return 0;
}