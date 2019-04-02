#include "lc.h"

class WordDictionary {
    struct TrieNode
    {
        bool _self_in;
        vector<TrieNode*> _children;
        
        TrieNode() : _self_in(false) {}
    };
    
    TrieNode *_root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        _root = NULL;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (!_root)
            _root = new TrieNode;
        TrieNode *p = _root;
        for (char c : word)
        {
            if (p->_children.empty())
            {   
                p->_children.resize(26);
                fill(p->_children.begin(), p->_children.end(), nullptr);
            }
            if (!p->_children[c - 'a'])
            {
                p->_children[c - 'a'] = new TrieNode;
            }
            p = p->_children[c - 'a'];
        }
        p->_self_in = true;
    }
    
    bool search_aux(TrieNode *p, const string& word, int idx)
    {
        if (!p) return false;
        int len = word.size();
        if (idx >= len) {
            if (p->_self_in)    return true;
            else    return false;
        }
        for (int i = idx; i < len; ++i)
        {
            if (!p || p->_children.empty()) return false;
            if (word[i] != '.')
            {
                p = p->_children[word[i] - 'a'];
            }
            else
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (search_aux(p->_children[j], word, i + 1))
                        return true;
                }
            }
        }
        if (p && p->_self_in)   return true;
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.size();
        TrieNode *p = _root;
        for (int i = 0; i < len; ++i)
        {
            if (!p || p->_children.empty()) return false;
            if (word[i] != '.')
            {
                p = p->_children[word[i] - 'a'];
            }
            else
                return search_aux(p, word, i);
        }
        if (p && p->_self_in)    return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 int main(int argc, char const *argv[])
 {
 	WordDictionary wd;
 	wd.addWord("a");
 	wd.addWord("a");
 	bool ret1 = wd.search(".");
 	bool ret2 = wd.search("aa");
 	bool ret3 = wd.search(".a");
 	return 0;
 }