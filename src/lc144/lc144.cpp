#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> tmp;
        TreeNode* p = root;
        while (p || !tmp.empty())
        {
            if (p)
            {
                ret.push_back(p->val);
                if (p->right)
                {
                    tmp.push(p->right);
                }
                p = p->left;
            }
            else
            {
                p = tmp.top();
                tmp.pop();
            }
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
		cout << toString(Solution().preorderTraversal(btree.root)) << endl;
	}
	return 0;
}