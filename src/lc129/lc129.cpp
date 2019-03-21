#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        vector<int> leaves;
        queue<int> valque;
        queue<TreeNode*> nodeque;
        valque.push(0);
        nodeque.push(root);
        while (!nodeque.empty())
        {
            queue<TreeNode*> tmpnodeque;
            queue<int> tmpvalque;
            while (!nodeque.empty())
            {
                TreeNode *p = nodeque.front();
                nodeque.pop();
                int curNum = valque.front();
                valque.pop();
                if (!p->left && !p->right)
                {
                    leaves.push_back(curNum * 10 + p->val);
                }
                if (p->left)
                {
                    tmpnodeque.push(p->left);
                    tmpvalque.push(curNum * 10 + p->val);
                }
                if (p->right)
                {
                    tmpnodeque.push(p->right);
                    tmpvalque.push(curNum * 10 + p->val);
                }
            }
            swap(nodeque, tmpnodeque);
            swap(valque, tmpvalque);
        }
        return accumulate(leaves.begin(), leaves.end(), 0);
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		cout << toString(Solution().sumNumbers(btree.root)) << endl;
	}
	return 0;
}