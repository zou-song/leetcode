#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)  return ret;
        stack<TreeNode*> tmp;
        tmp.push(root);
        int depth = 0;
        while (!tmp.empty())
        {
            depth++;
            vector<int> vec;
            stack<TreeNode*> tmplist;
            while (!tmp.empty())
            {
                TreeNode *p = tmp.top();
                tmp.pop();
                vec.push_back(p->val);
                if (depth % 2)
                {
                    if (p->left)
                        tmplist.push(p->left);
                    if (p->right)
                        tmplist.push(p->right);
                }
                else
                {
                    if (p->right)
                        tmplist.push(p->right);
                    if (p->left)
                        tmplist.push(p->left);
                }
            }
            ret.push_back(vec);
            swap(tmp, tmplist);
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
		cout << toString(Solution().zigzagLevelOrder(btree.root)) << endl;
	}
	return 0;
}
