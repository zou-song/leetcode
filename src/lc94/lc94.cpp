#include "lc.h"

typedef LCBinaryTreeNode<T> TreeNode;

class Solution {
public:
    //an easy but time-cost way
    void inorderTraversal(TreeNode* node, vector<int> &ret)
    {
        if (!node)  return;
        inorderTraversal(node->left, ret);
        ret.push_back(node->val);
        inorderTraversal(node->right, ret);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)  return ret;
        stack<TreeNode*> tmp;
        TreeNode *node = root;
        while (node || !tmp.empty())
        {
            if (!node)
            {
                node = tmp.top();
                ret.push_back(node->val);
                node = node->right;
                tmp.pop();
            }
            else
            {
                tmp.push(node);
                node = node->left;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree bt;
		walkString(bt, line);
		auto output = Solution().inorderTraversal(bt.root);
		cout << toString(bt) << endl;
		cout << toString(output) << endl;
	}
	return 0;
}