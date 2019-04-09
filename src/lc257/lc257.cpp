#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    void binaryTreePaths(TreeNode* root, const string& path, vector<string>& ret)
    {
        if (!root)  return;
        string s;
        if (path.empty())
            s = to_string(root->val);
        else
            s = path + "->" + to_string(root->val);
        if (!root->left && !root->right)
        {
            ret.push_back(s);
            return;
        }
        if (root->left)
            binaryTreePaths(root->left, s, ret);
        if (root->right)
            binaryTreePaths(root->right, s, ret);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        binaryTreePaths(root, "", ret);
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
		cout << toString(Solution().binaryTreePaths(btree.root)) << endl;
	}
	return 0;
}