#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)  return false;
        queue<int> sums;
        queue<TreeNode*> que;
        que.push(root);
        sums.push(root->val);
        while (true)
        {
            queue<TreeNode*> tmp;
            queue<int> sumtmp;
            while (!que.empty())
            {
                TreeNode *p = que.front();
                que.pop();
                int s = sums.front();
                sums.pop();
                if (!p->left && !p->right)
                {
                    if (s == sum)
                        return true;
                }
                if (p->left)
                {
                    tmp.push(p->left);
                    sumtmp.push(s + p->left->val);
                }
                if (p->right)
                {
                    tmp.push(p->right);
                    sumtmp.push(s + p->right->val);
                }
            }
            swap(que, tmp);
            swap(sums, sumtmp);
            if (que.empty())
                break;
        }
        return false;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		getline(cin, line);
		int sum = 0;
		walkString(sum, line);
		cout << toString(Solution().hasPathSum(btree.root, sum)) << endl;
	}
	return 0;
}