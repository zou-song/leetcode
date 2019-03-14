#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int idx1, int idx2)
    {
        if (idx1 > idx2)    return NULL;
        int mid = (idx1 + idx2) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, idx1, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, idx2);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return sortedArrayToBST(nums, 0, len - 1);
    }
};

int main()
{
	string line;
	while(getline(cin, line))
	{
		vector<int> nums;
		walkString(nums, line);
		LCBinaryTree<int> btree;
		btree.root = Solution().sortedArrayToBST(nums);
		cout << toString(btree) << endl;
	}
	return 0;
}