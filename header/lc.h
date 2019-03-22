#ifndef __LEETCODE_LC_H__
#define __LEETCODE_LC_H__

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <assert.h>
#include <memory.h>

//just for convenience, not appropriate to using namespace in the header file
using namespace std;

//functions below are auxiliary functions used in the main function, copied from leetcode website
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

template<typename T>
struct LCListNode
{
    T val;
    LCListNode *next;
    LCListNode(const T& v) : val(v), next(NULL){}
};

template<typename T>
struct LCList
{
    LCListNode<T> *head;

    LCList(){ head = NULL; }
	LCList(const LCList<T> &l): head(NULL)
	{
		head = deepCopy(l);
	}
	LCList(LCList<T> &&l) : head(NULL) { swap(head, l.head); }
    LCList(LCListNode<T> &ptr) : head(ptr) {}

	LCList& operator = (const LCList<T> &rhs)
	{
		if (this == &rhs)
			return *this;
		LCList<T> tmp;
		tmp.head = deepCopy(rhs);
		swap(head, tmp.head);
		return *this;
	}
	LCList& operator = (LCList<T> &&rhs)
	{
		swap(head, rhs.head);
		return *this;
	}
	
	static LCListNode<T>* deepCopy(const LCList<T> &l)
	{
		LCListNode<T> *p = l.head;
		LCListNode<T> *pre = NULL;
		LCListNode<T> *ret = NULL;
		while (p)
		{
			LCListNode<T> *pnode = new LCListNode<T>(p->val);
			if (!ret)
				ret = pnode;
			if (pre)
				pre->next = pnode;
			pre = pnode;
			p = p->next;
		}
		return ret;
	}

    ~LCList()
    {
        destroyList();
    }
    void destroyList()
    {
        while (head && head->next)
        {
            LCListNode<T> *next = head->next;
            delete head;
            head = next;
        }
        head = NULL;
    }

    void parseFromString(string &str);
    string toStr() const;
};

template<typename T>
struct LCBinaryTreeNode
{
    T val;
    LCBinaryTreeNode *left;
    LCBinaryTreeNode *right;
    LCBinaryTreeNode(): val(0), left(NULL), right(NULL){}
    LCBinaryTreeNode(const T& v) : val(v), left(NULL), right(NULL){}
};

template<typename T>
struct LCBinaryTree
{
    LCBinaryTreeNode<T> *root;

    LCBinaryTree(): root(NULL) {}
    LCBinaryTree(LCBinaryTreeNode<T> *ptr): root(ptr) {}
	LCBinaryTree(LCBinaryTree<T> &&tree): root(NULL) {swap(root, tree.root);}

    ~LCBinaryTree()
    {
        destroyBinaryTree(root);
    }
    static void destroyBinaryTree(LCBinaryTreeNode<T> *ptr)
    {
        if (!ptr)   return;
        destroyBinaryTree(ptr->left);
        destroyBinaryTree(ptr->right);
        delete ptr;
    }

    LCBinaryTree& operator = (LCBinaryTreeNode<T> *ptr)
    {
        root = ptr;
        return *this;
    }
	LCBinaryTree& operator = (LCBinaryTree<T> &&tree)
	{
		swap(root, tree.root);
		return *this;
	}

    void parseFromString(string &str);
    string toStr() const;
};

//functions to build structured data form string
template<typename T>
void walkString(T &t, string &str)
{
    t.parseFromString(str);
}

template<typename T>
void walkString(T* &p, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    if (str.empty())
        throw invalid_argument("parse failed");
    size_t idx = str.find_first_of(",]");
    string tmp = str.substr(0, idx);
    trimRightTrailingSpaces(tmp);
    if (tmp == "null" || tmp == "NULL")
    {
        p = NULL;
        size_t idx2 = str.find_first_not_of(", ", idx);
        if (idx2 == string::npos)
            str = "";
        else
            str = str.substr(idx2);
    }
    else
    {
        p = new T;
        walkString(*p, str);
    }
}

template<> void walkString(int &n, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    size_t idx = 0;
    n = stoi(str, &idx);
    idx = str.find_first_not_of(", ", idx);
	if (idx == string::npos)
		str = "";
	else
    	str = str.substr(idx);
}

template<> void walkString(char &s, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    if (str.empty() || str[0] != '"' || str.size() < 3)
        throw invalid_argument("cannot parse to char");
	size_t i = 1;
	char currentChar = str[i];
	if (str[i] == '\\') {
		char nextChar = str[i+1];
		switch (nextChar) {
			case '\"': s = '\"'; break;
			case '/' : s = '/'; break;
			case '\\': s = '\\'; break;
			case 'b' : s = '\b'; break;
			case 'f' : s = '\f'; break;
			case 'r' : s = '\r'; break;
			case 'n' : s = '\n'; break;
            case 't' : s = '\t'; break;
			default: break;
		}
		i++;
	} else {
		s = currentChar;
	}
	if (str.size() == i + 1 || str[i + 1] != '"')
        throw invalid_argument("cannot parse to char");
	size_t idx = str.find_first_not_of(", ", i + 2);
	if (idx == string::npos)
		str = "";
	else
		str = str.substr(idx);
}

template<> void walkString(string &s, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    if (str.empty() || str[0] != '"')
        throw invalid_argument("cannot parse to string");
    size_t end = str.find_first_of('"', 1);
    if (end == string::npos)
        throw invalid_argument("cannot parse to string");
	for (size_t i = 1; i < end; ++i)
	{
		char currentChar = str[i];
        if (str[i] == '\\') {
            char nextChar = str[i+1];
            switch (nextChar) {
                case '\"': s.push_back('\"'); break;
                case '/' : s.push_back('/'); break;
                case '\\': s.push_back('\\'); break;
                case 'b' : s.push_back('\b'); break;
                case 'f' : s.push_back('\f'); break;
                case 'r' : s.push_back('\r'); break;
                case 'n' : s.push_back('\n'); break;
                case 't' : s.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          s.push_back(currentChar);
        }
	}
    size_t idx = str.find_first_not_of(", ", end + 1);
	if (idx == string::npos)
		str = "";
	else
		str = str.substr(idx);
}

template<typename T> 
void walkString(vector<T> &vec, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    if (str.empty() || str[0] != '[')
        throw invalid_argument("cannot parse to vector");
	str.erase(0, 1);
    while (!str.empty() && str[0] != ']')
    {
        T t;
        walkString(t, str);
        vec.push_back(move(t));
    }
    if (str.empty())
        throw invalid_argument("cannot parse to vector");
    size_t idx = str.find_first_not_of(", ", 1);
    if (idx == string::npos)
		str = "";
	else
		str = str.substr(idx);
}

template<typename T>
void LCList<T>::parseFromString(string &str)
{
    vector<T> tmp;
    walkString(tmp, str);
    LCList<T> tmplist;
    LCListNode<T> *pre = NULL;
    for (auto &t : tmp)
    {
        LCListNode<T> *node = new LCListNode<T>(t);
        if (!pre)
        {
            pre = node;
            tmplist.head = pre;
        }
        else
        {
            pre->next = node;
            pre = pre->next;
        }
    }
    swap(head, tmplist.head);
}

template<typename T>
void walkString(LCBinaryTreeNode<T> &node, string &str)
{
    walkString(node.val, str);
}

template<typename T>
void LCBinaryTree<T>::parseFromString(string &str)
{
    vector<LCBinaryTreeNode<T>*> tmp;
    walkString(tmp, str);
    if (tmp.empty())
    {
        root = NULL;
        return;
    }
    root = tmp[0];
    int len = tmp.size();
    int idx1 = 0, idx2 = 1;
    LCBinaryTreeNode<T> *node = tmp[0];
    while (idx1 < len - 1 && idx2 < len)
    {
        if (!node)
            node = tmp[++idx1];
        else
        {
            node->left = tmp[idx2++];
            if (idx2 >= len)
                node->right = NULL;
            else
                node->right = tmp[idx2++];
			node = tmp[++idx1];
        }
    }
}

//functions to build string from structured data
template<typename T>
string toString(const T &t)
{
    return t.toStr();
}

template<typename T>
string toString(T *p)
{
    if (!p) return "null";
    return toString(*p);
}

template<> string toString(const bool &b)
{
	return b ? "True" : "False";
}

template<> string toString(const int &n)
{
    return to_string(n);
}

template<> string toString(const char &c)
{
    return '"' + string(1, c) + '"';
}

template<> string toString(const string &str)
{
    return '"' + str + '"';
}

template<typename T>
string toString(const vector<T> &vec)
{
    string ret;
    int len = vec.size();
    for (int i = 0; i < len; ++i)
    {
        ret = ret + toString(vec[i]);
        if (i != len - 1)
        {
            ret += ", ";
        }
    }
    return '[' + ret + ']';
}

template<typename T>
string toString(const LCBinaryTreeNode<T> &node)
{
	return toString(node.val);
}

template<typename T>
string LCList<T>::toStr() const
{
    vector<T> tmp;
    LCListNode<T> *node = head;
    while (node)
    {
        tmp.push_back(node->val);
        node = node->next;
    }
    return toString(tmp);
}

template<typename T>
string LCBinaryTree<T>::toStr() const
{
    list<LCBinaryTreeNode<T>*> tmplist;
    vector<LCBinaryTreeNode<T>*> tmpvec;
    tmplist.push_back(root);
    while (!tmplist.empty())
    {
        LCBinaryTreeNode<T> *p = tmplist.front();
        tmplist.pop_front();
        tmpvec.push_back(p);
        if (p)
        {
            tmplist.push_back(p->left);
            tmplist.push_back(p->right);
        }
    }
	while (!tmpvec.empty() && tmpvec.back() == NULL)
	{
		tmpvec.pop_back();
	}
    return toString(tmpvec);
}

//functions used in leetcode main
int stringToInteger(string input) {
    int n = 0;
	walkString(n, input);
	return n;
}

string stringToString(string input) {
	string output;
	walkString(output, input);
    return output;
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
	walkString(output, input);
    return output;
}

vector<string> stringToStringVector(string input)
{
    vector<string> output;
	walkString(output, input);
    return output;
}

vector<vector<int>> stringToIntegerVectorVector(string input)
{
	vector<vector<int>> output;
	walkString(output, input);
    return output;
}

string boolToString(bool input) {
	return toString(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length < 0) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

	list.resize(length);
	return toString(list);
}

string intergerVectorVectorToString(const vector<vector<int>> &vec2)
{
	return toString(vec2);
}

string stringVectorToString(const vector<string>& vec)
{
	return toString(vec);
}



#endif
