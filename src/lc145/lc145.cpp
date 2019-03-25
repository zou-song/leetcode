#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode*, int>> tmp;
        TreeNode *p = root;
        while (p || !tmp.empty())
        {
            if (p)
            {
                tmp.emplace(p, 0);
                p = p->left;
            }
            else
            {
                auto &pr = tmp.top();
                if (pr.second == 0)
                {
                    p = pr.first->right;
                    pr.second++;
                }
                else
                {
                    ret.push_back(pr.first->val);
                    tmp.pop();
                }
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
		cout << toString(Solution().postorderTraversal(btree.root)) << endl;
	}
	return 0;
}
