#include "lc.h"

class Solution {
    struct TrieNode
    {
        string _str;
        TrieNode *_children[26];
        
        TrieNode()
        {
            memset(_children, 0, 26 * sizeof(TrieNode*));
        }
    };
    
    TrieNode *_root;
    void BuildTrieTree(const vector<string>& words)
    {
        if (words.empty())  return;
        if (!_root)
            _root = new TrieNode;
        for (auto &str : words)
        {
            TrieNode *p = _root;
            for (char c : str)
            {
                if (!p->_children[c - 'a'])
                    p->_children[c - 'a'] = new TrieNode;
                p = p->_children[c - 'a'];
            }
            p->_str = str;
        }
    }
    
    void DFS(vector<vector<char>>& board, int r, int c, TrieNode *p, vector<string>& ret)
    {
        if (!p) return;
        int rows = board.size();
        int cols = board[0].size();
        if (board[r][c] == '*' || !p->_children[board[r][c] - 'a'])   return;
        
        char bc = board[r][c];
        board[r][c] = '*';
        
        p = p->_children[bc - 'a'];
        if (!p->_str.empty())
        {
            ret.push_back(p->_str);
            p->_str.clear();
        }
        
        if (r > 0 && board[r - 1][c] != '*')
            DFS(board, r - 1, c, p, ret);
        if (r < rows - 1 && board[r + 1][c] != '*')
            DFS(board, r + 1, c, p, ret);
        if (c > 0 && board[r][c - 1] != '*')
            DFS(board, r, c - 1, p, ret);
        if (c < cols - 1 && board[r][c + 1] != '*')
            DFS(board, r, c + 1, p, ret);
        board[r][c] = bc;
    }
    
public:    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        BuildTrieTree(words);
        int rows = board.size();
        if (rows <= 0)  return ret;
        int cols = board[0].size();
        if (cols <= 0)  return ret;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
            {
                DFS(board, i, j, _root, ret);
            }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<vector<char>> board;
		walkString(board, line);
		getline(cin, line);
		vector<string> words;
		walkString(words, line);
		cout << toString(Solution().findWords(board, words)) << endl;
	}
	return 0;
}