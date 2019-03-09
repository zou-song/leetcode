#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        list<TreeNode*> llist, rlist;
        llist.push_back(p);
        rlist.push_back(q);
        while (!llist.empty() && !rlist.empty())
        {
            TreeNode *ln = llist.front();
            llist.pop_front();
            TreeNode *rn = rlist.front();
            rlist.pop_front();
            if (!ln && rn)  return false;
            else if (ln && !rn)  return false;
            else if (!ln && !ln)    continue;
            else if (ln->val != rn->val) return false;
            llist.push_back(ln->left);
            llist.push_back(ln->right);
            rlist.push_back(rn->left);
            rlist.push_back(rn->right);
        }
        if (!llist.empty())  return false;
        if (!rlist.empty())  return false;
        return true;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> ltree, rtree;
		walkString(ltree, line);
		getline(cin, line);
		walkString(rtree, line);
		cout << toString(Solution().isSameTree(ltree.root, rtree.root)) << endl;
	}
	return 0;
}