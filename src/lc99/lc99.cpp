#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root)  return;
        vector<int> tmpvec;
        stack<TreeNode*> tmpstk;
        TreeNode *node = root;
        while (node || !tmpstk.empty())
        {
            if (node)
            {
                tmpstk.push(node);
                node = node->left;
            }
            else
            {
                node = tmpstk.top();
                tmpstk.pop();
                tmpvec.push_back(node->val);
                node = node->right;
            }
        }
        sort(tmpvec.begin(), tmpvec.end());
        node = root;
        int idx = 0;
        while (node || !tmpstk.empty())
        {
            if (node)
            {
                tmpstk.push(node);
                node = node->left;
            }
            else
            {
                node = tmpstk.top();
                tmpstk.pop();
                node->val = tmpvec[idx++];
                node = node->right;
            }
        }
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> input;
		walkString(input, line);
		Solution().recoverTree(input.root);
		cout << toString(input) << endl;
	}
	return 0;
}