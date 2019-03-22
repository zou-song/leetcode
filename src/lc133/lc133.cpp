#include "lc.h"


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors = {}) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return NULL;
        vector<Node*> newVec, oldVec;
        unordered_map<Node*, int> nodeIdxMap;
        queue<Node*> newQue, oldQue;
        Node *root = new Node(node->val);
        newVec.push_back(root);
        oldVec.push_back(node);
        nodeIdxMap[node] = 0;
        newQue.push(root);
        oldQue.push(node);
        unordered_set<Node*> finishNodeSet;
        while (!oldQue.empty())
        {
            Node *newNode = newQue.front();
            newQue.pop();
            Node *oldNode = oldQue.front();
            oldQue.pop();
            if (finishNodeSet.count(oldNode))
                continue;
            for (auto p : oldNode->neighbors)
            {
                auto iter = nodeIdxMap.find(p);
                if (iter != nodeIdxMap.end())
                {
                    newNode->neighbors.push_back(newVec[iter->second]);
                    if (finishNodeSet.count(p) == 0)
                    {
                        newQue.push(newVec[iter->second]);
                        oldQue.push(p);
                    }
                }
                else
                {
                    Node* nd = new Node(p->val);
                    newNode->neighbors.push_back(nd);
                    newVec.push_back(nd);
                    oldVec.push_back(p);
                    nodeIdxMap[p] = oldVec.size() - 1;
                    if (finishNodeSet.count(p) == 0)
                    {
                        newQue.push(nd);
                        oldQue.push(p);
                    }
                }
            }
            finishNodeSet.insert(oldNode);
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
	//parser undo
	return 0;
}
