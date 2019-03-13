#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)  return ret;
        list<TreeNode*> tmp;
        tmp.push_back(root);
        while (!tmp.empty())
        {
            int len = tmp.size();
            vector<int> vec;
            for (int i = 0; i < len; ++i)
            {
                TreeNode *p = tmp.front();
                tmp.pop_front();
                vec.push_back(p->val);
                if (p->left)
                    tmp.push_back(p->left);
                if (p->right)
                    tmp.push_back(p->right);
            }
            ret.push_back(vec);
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
		cout << toString(Solution().levelOrder(btree.root)) << endl;
	}
	return 0;
}