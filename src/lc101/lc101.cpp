#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        list<TreeNode*> llist, rlist;
        if (!root)  return true;
        llist.push_back(root->left);
        rlist.push_back(root->right);
        while (!llist.empty() && !rlist.empty())
        {
            int llen = llist.size();
            int rlen = rlist.size();
            if (llen != rlen)   return false;
            for (int i = 0; i < llen; ++i)
            {
                TreeNode *lp = llist.front();
                TreeNode *rp = rlist.front();
                if (lp && !rp)  return false;
                else if (!lp && rp) return false;
                else if (!lp && !rp)
                {
                    llist.pop_front();
                    rlist.pop_front();
                }
                else
                {
                    if (lp->val != rp->val)
                        return false;
                    llist.push_back(lp->left);
                    llist.push_back(lp->right);
                    rlist.push_back(rp->right);
                    rlist.push_back(rp->left);
                    llist.pop_front();
                    rlist.pop_front();
                }
            }
        }
        return true;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        LCBinaryTree<int> btree;
        walkString(btree, line);
        cout << toString(Solution().isSymmetric(btree.root)) << endl;
    }
    return 0;
}