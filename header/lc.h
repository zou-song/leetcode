#ifndef __LEETCODE_LC_H__
#define __LEETCODE_LC_H__

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <numeric>
#include <stdexcept>
#include <sstream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>
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
    LCList(LCListNode<T> &ptr) : head(ptr) {}
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

//functions to build structured data form string
template<typename T>
void walkString(T &t, string &str)
{
    t.parseFromString(str);
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
        vec.push_back(t);
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

//functions to build string from structured data
template<typename T>
string toString(const T &t)
{
    return t.toStr();
}

template<> string toString(const bool &b)
{
	return b ? "True" : "False";
}

template<> string toString(const int &n)
{
    return to_string(n);
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
