#include "lc.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        list<Node*> links;
        links.push_back(root);
        while (!links.empty())
        {
            list<Node*> tmp;
            Node *pre = NULL;
            while (!links.empty())
            {
                Node *p = links.front();
                links.pop_front();
                if (p && p->left)
                {
                    tmp.push_back(p->left);
                }
                if (p && p->right)
                {
                    tmp.push_back(p->right);
                }
                if (pre)
                {
                    pre->next = p;
                }
                pre = p;
            }
            if (pre)
            {
                pre->next = NULL;
            }
            swap(links, tmp);
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}