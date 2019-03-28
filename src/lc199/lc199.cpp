#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> que;
        if (!root)  return ret;
        que.push(root);
        while (!que.empty())
        {
            queue<TreeNode*> tmp;
            ret.push_back(que.back()->val);
            while (!que.empty())
            {
                TreeNode *p = que.front();
                que.pop();
                if (p->left)
                    tmp.push(p->left);
                if (p->right)
                    tmp.push(p->right);
            }
            swap(que, tmp);
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
		cout << toString(Solution().rightSideView(btree.root)) << endl;
	}
	return 0;
}