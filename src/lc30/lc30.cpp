#include "lc.h"

class Solution {
    static const int DICT_LEN = 26;
    struct DictNode{
        int _old_times;
        int _cur_times;
        bool _self;
        vector<DictNode*> _children;
        
        DictNode() : _old_times(0), _cur_times(0), _self(false){}
    };
    DictNode _head;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int words_size = 0;
        for (string &str : words)
        {
            int len = str.size();
            words_size += len;
            DictNode *p = &_head;
            for (int i = 0; i < len; ++i)
            {
                int idx = str[i] - 'a';
                if (p->_children.empty())
                {
                    p->_children.resize(DICT_LEN);
                    fill(p->_children.begin(), p->_children.end(), nullptr);
                }
                if (!p->_children[idx])
                    p->_children[idx] = new DictNode;
                p = p->_children[idx];
            }
            p->_self = true;
            p->_old_times++;
        }
        int len = s.size();
        vector<int> ret;
        for (int i = 0; i < len - words_size + 1; ++i)
        {
            DictNode *p = &_head;
            vector<DictNode*> found;
            int found_num = 0;
            for (int j = i; j < i + words_size; j++)
            {
                int idx = s[j] - 'a';
                if (p->_children.empty() || !p->_children[idx])
                    break;
                p = p->_children[idx];
                if (p->_self)
                {//found
                    if (p->_cur_times == 0)
                    {
                        found.push_back(p);
                    }
                    if (++p->_cur_times > p->_old_times)
                        break;
                    p = &_head;
                    found_num++;
                }
            }
            if ((size_t)found_num == words.size() && found_num != 0)
            {
                ret.push_back(i);
            }
            for_each(found.begin(), found.end(), [](DictNode *p){
                p->_cur_times = 0;
            });
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string s;
		walkString(s, line);
		getline(cin, line);
		vector<string> words;
		walkString(words, line);
		cout << toString(Solution().findSubstring(s, words)) << endl;
	}
	return 0;
}
