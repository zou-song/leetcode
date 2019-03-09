#include "lc.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(const vector<int>& nums, int beg, int end)
    {
        if (beg >= end)
            return {NULL};
        vector<TreeNode*> ret;
        for (int i = beg; i != end; ++i)
        {
            auto left = generateTrees(nums, beg, i);
            auto right = generateTrees(nums, i + 1, end);
            for (auto pl : left)
            {
                for (auto pr : right)
                {
                    TreeNode *root = new TreeNode(nums[i]);
                    root->left = pl;
                    root->right = pr;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if (n < 1)  return ret;
        vector<int> nums(n);
        int tmp = 1;
        generate(nums.begin(), nums.end(), [&tmp](){
            return tmp++;
        });
        return generateTrees(nums, 0, n);
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		int n = 0;
		walkString(n, line);
		auto vec = Solution().generateTrees(n);
		vector<LCBinaryTree<int>> output(vec.size());
		transform(vec.begin(), vec.end(), output.begin(), [](const TreeNode* ptr){
			return ptr;
		});
		cout << toString(output) << endl;
	}
	return 0;
}