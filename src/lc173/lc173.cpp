#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class BSTIterator {
    vector<TreeNode*> _vec;
    int _idx;
public:
    BSTIterator(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> tmp;
        while (p || !tmp.empty())
        {
            if (p)
            {
                tmp.push(p);
                p = p->left;
            }
            else
            {
                p = tmp.top();
                tmp.pop();
                _vec.push_back(p);
                p = p->right;
            }
        }
        _idx = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return _vec[_idx++]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _idx < _vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}