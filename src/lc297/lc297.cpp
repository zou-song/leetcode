#include "lc.h"

typedef LCBinaryTreeNode<int> TreeNode;

class Codec {
    const string START_SYMBOL = "[";
    const string END_SYMBOL = "]";
    const string SEPERATOR = ",";
    const string NULL_STRING = "N";
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        list<TreeNode*> bfs_list;
        list<TreeNode*> tmp_list;
        bool has_child = false;
        bfs_list.push_back(root);
        while (!bfs_list.empty())
        {
            TreeNode *p = bfs_list.front();
            bfs_list.pop_front();
            if (p)
            {
                if (ret.empty())
                    ret = to_string(p->val);
                else
                    ret = ret + SEPERATOR + to_string(p->val);
                tmp_list.push_back(p->left);
                tmp_list.push_back(p->right);
                if (p->left || p->right)
                    has_child = true;
            }
            else
            {
                if (ret.empty())
                    ret = NULL_STRING;
                else
                    ret = ret + SEPERATOR + NULL_STRING;
            }
            if (bfs_list.empty() && has_child)
            {
                swap(bfs_list, tmp_list);
                has_child = false;
            }
        }
        return START_SYMBOL + ret + END_SYMBOL;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.pop_back();
        data.erase(0,1);
        int len = data.size();
        TreeNode *root = NULL;
        list<TreeNode*> bfs_list;
        int idx = 0;
        bool left_flag = true;
        while (idx < len)
        {
            int end = idx + 1;
            while (end < len && data[end] != ',')
                end++;
            string str = data.substr(idx, end - idx);
            TreeNode *p = NULL;
            if (str != NULL_STRING)
            {
                int val = stoi(str);
                p = new TreeNode(val);
            }
            if (!root)
            {
                root = p;
            }
            else
            {
                if (left_flag)
                {
                    bfs_list.front()->left = p;
                    left_flag = false;
                }
                else
                {
                    bfs_list.front()->right = p;
                    left_flag = true;
                    bfs_list.pop_front();
                }
            }
            if (p)
            {
                bfs_list.push_back(p);
            }
            idx = end + 1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		LCBinaryTree<int> btree;
		walkString(btree, line);
		Codec codec;
		LCBinaryTree<int> codec_tree;
		codec_tree.root = codec.deserialize(codec.serialize(btree.root));
		cout << toString(codec_tree) << endl;
	}
	return 0;
}
