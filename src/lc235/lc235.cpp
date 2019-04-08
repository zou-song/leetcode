#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
	bool findNode(TreeNode *root, int n, vector<TreeNode*> &paths)
    {
    	if (!root)  return false;
        if (root->val == n)
        {
            paths.push_back(root);
            return true;
        }
        paths.push_back(root);
        if (findNode(root->left, n, paths))
            return true;
        if (findNode(root->right, n, paths))
            return true;
        paths.pop_back();
        return false;
    }

    bool findNode(TreeNode *root, TreeNode *p, vector<TreeNode*> &paths)
    {
        if (root == p)
        {
            paths.push_back(root);
            return true;
        }
        if (!root)  return false;
        paths.push_back(root);
        if (findNode(root->left, p, paths))
            return true;
        if (findNode(root->right, p, paths))
            return true;
        paths.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pvec, qvec;
        findNode(root, p, pvec);
        findNode(root, q, qvec);
        int plen = pvec.size();
        int qlen = qvec.size();
        int idx = 0;
        while (idx < plen && idx < qlen && pvec[idx] == qvec[idx])
        {
            idx++;
        }
        if (idx <= 0)   return NULL;
        return pvec[idx - 1];
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root || !p || !q)  return NULL;
        if (p->val == root->val || q->val == root->val) return root;
        if (p->val > q->val)    swap(p, q);
        if (p->val < root->val && q->val > root->val)   return root;
        else if (p->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		int p = 0, q = 0;
		getline(cin, line);
		walkString(p, line);
		getline(cin, line);
		walkString(q, line);
		vector<TreeNode*> pvec = {NULL}, qvec = {NULL};
		Solution().findNode(btree.root, p, pvec);
		Solution().findNode(btree.root, q, qvec);
		TreeNode *ret = Solution().lowestCommonAncestor(btree.root, pvec.back(), qvec.back());
		if (!ret)	cout << "NULL" << endl;
		else	cout << ret->val << endl;
	}
	return 0;
}