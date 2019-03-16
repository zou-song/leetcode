#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    int maxPathSum(TreeNode* root, int& ret)
    {
        if (!root)  return 0;
        if (!root->left && !root->right)
        {
            if (root->val > ret)
                ret = root->val;
            return root->val;
        }
        int left = maxPathSum(root->left, ret);
        int right = maxPathSum(root->right, ret);
        vector<int> v(4);
        v[0] = root->val;
        v[1] = root->val + left;
        v[2] = root->val + right;
        v[3] = root->val + left + right;
        int tmp = *max_element(v.begin(), v.end());
        if (tmp > ret)
            ret = tmp;
        return *max_element(v.begin(), v.end() - 1);
    }
    
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        maxPathSum(root, ret);
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
		cout << toString(Solution().maxPathSum(btree.root)) << endl;
	}
	return 0;
}