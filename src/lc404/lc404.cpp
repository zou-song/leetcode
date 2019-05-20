#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    void func(TreeNode *p, bool is_left, int &sum)
    {
        if (!p)
        {
            return;
        }
        if (!p->left && !p->right)
        {
            if (is_left)
            {
                sum += p->val;
            }
            return;
        }
        func(p->left, true, sum);
        func(p->right, false, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        func(root, false, sum);
        return sum;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		cout << toString(Solution().sumOfLeftLeaves(btree.root)) << endl;
	}
	return 0;
}