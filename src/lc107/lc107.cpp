#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)  return ret;
        queue<TreeNode*> que;
        que.push(root);
        while (true)
        {
            vector<int> vec;
            queue<TreeNode*> tmp;
            while (!que.empty())
            {
                TreeNode *p = que.front();
                que.pop();
                vec.push_back(p->val);
                if (p->left)
                    tmp.push(p->left);
                if (p->right)
                    tmp.push(p->right);
            }
            ret.push_back(vec);
            swap(tmp, que);
            if (que.empty())
                break;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		LCBinary<int> btree;
		walkString(btree, line);
		auto output = Solution().levelOrderBottom(btree.root);
		cout << toString(output) << endl;
	}
	return 0;
}