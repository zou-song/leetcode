#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    void pathSum(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int>& vec, int cur_sum)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            if (cur_sum + root->val == sum)
            {
                vec.push_back(root->val);
                ret.push_back(vec);
                vec.pop_back();
            }
            return;
        }
        cur_sum += root->val;
        vec.push_back(root->val);
        if (root->left)
            pathSum(root->left, sum, ret, vec, cur_sum);
        if (root->right)
            pathSum(root->right, sum, ret, vec, cur_sum);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> vec;
        pathSum(root, sum, ret, vec, 0);
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
		int sum = 0;
		getline(cin, line);
		walkString(sum, line);
		cout << toString(Solution().pathSum(btree.root, sum)) << endl;
	}
	return 0;
}