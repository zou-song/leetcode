#include "lc.h"

class Trie {
    struct TrieNode
    {
        vector<TrieNode*> _tree;
        TrieNode()
        {
            _tree.resize(27);
            fill(_tree.begin(), _tree.end(), nullptr);
        }
    };
    TrieNode* _trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        _trie = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = _trie;
        for (char c : word)
        {
            if (p->_tree[c - 'a'])
                p = p->_tree[c - 'a'];
            else
            {
                p->_tree[c - 'a'] = new TrieNode;
                p = p->_tree[c - 'a'];
            }
        }
        if (p->_tree[26] == NULL)
            p->_tree[26] = new TrieNode;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = _trie;
        for (char c : word)
        {
            if (p->_tree[c - 'a'] == NULL)
                return false;
            else p = p->_tree[c - 'a'];
        }
        return p->_tree[26];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = _trie;
        for (char c : prefix)
        {
            if (p->_tree[c - 'a'] == NULL)
                return false;
            else p = p->_tree[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }