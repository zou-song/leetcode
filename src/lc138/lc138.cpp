#include "lc.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return NULL;
        unordered_map<Node*, int> nodeIdxMap;
        vector<Node*> newVec, oldVec;
        Node *root = new Node(head->val, NULL, NULL);
        newVec.push_back(root);
        oldVec.push_back(head);
        nodeIdxMap[head] = 0;
        Node *oldNode = head;
        Node *newNode = root;
        while (oldNode)
        {
            if (oldNode->next)
            {
                auto iter = nodeIdxMap.find(oldNode->next);
                if (iter != nodeIdxMap.end())
                {
                    newNode->next = newVec[iter->second];
                }
                else
                {
                    Node *nd = new Node(oldNode->next->val, NULL, NULL);
                    newNode->next = nd;
                    newVec.push_back(nd);
                    oldVec.push_back(oldNode->next);
                    nodeIdxMap[oldNode->next] = oldVec.size() - 1;
                }
            }
            if (oldNode->random)
            {
                auto iter = nodeIdxMap.find(oldNode->random);
                if (iter != nodeIdxMap.end())
                {
                    newNode->random = newVec[iter->second];
                }
                else
                {
                    Node *nd = new Node(oldNode->random->val, NULL, NULL);
                    newNode->random = nd;
                    newVec.push_back(nd);
                    oldVec.push_back(oldNode->random);
                    nodeIdxMap[oldNode->random] = oldVec.size() - 1;
                }
            }
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}