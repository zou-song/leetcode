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
void walkString(T &t, string &str)
{
    thorw invalid_argument("invalid value type: " + typeid(T).name());
}

template<> void walkString(int &n, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    size_t idx = 0;
    n = stoi(str, &idx);
    idx = str.find_first_not_of(", ", idx);
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
    s = str.substr(1, end - 1);
    size_t idx = str.find_first_not_of(", ", idx + 1);
    str = str.substr(idx);
}

template<typename T> 
void walkString(vector<T> &vec, string &str)
{
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    if (str.empty() || str[0] != '[')
        throw invalid_argument("cannot parse to vector");
    while (!str.empty() && str[0] != ']')
    {
        T t;
        walkString(t, str);
        vec.push_back(t);
    }
    if (str.empty())
        throw invalid_argument("cannot parse to vector");
    size_t idx = str.find_first_not_of(", ", 1);
    str = str.substr(idx);
}

template<typename T>
string toString(const T &t)
{
    throw invalid_argument("cannot convert to string: " + typeid(T).name());
    return "";
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
            ret += ", "
        }
    }
    return '[' + ret + ']';
}

int stringToInteger(string input) {
    return stoi(input);
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

vector<string> stringToStringVector(string input)
{
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        trimLeftTrailingSpaces(item);
        trimRightTrailingSpaces(item);
        output.push_back(item.substr(1, item.length() -2));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

string intergerVectorVectorToString(const vector<vector<int>> &vec2)
{
	if (vec2.empty())
		return "[]";
	string ret;
	for (auto &v : vec2)
	{
		string str;
		for (auto num : v)
		{
			str = str + to_string(num) + ", ";
		}
		ret = ret + "[" + str.substr(0, str.length() - 2) + "], ";
	}
	return "[" + ret.substr(0, ret.length() - 2) + "]";
}

string stringVectorToString(const vector<string>& vec)
{}

vector<vector<int>> stringToIntegerVectorVector(string input)
{
	vector<vector<int>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
	int beg = 0;
	int len = input.length();
	while (beg < len)
	{
		while (beg < len && input[beg] != '[')
		{
			beg++;
		}
		int end = beg;
		while (end < len && input[end] != ']')
		{
			end++;
		}
		if (beg < len)
			output.push_back(stringToIntegerVector(input.substr(beg, end - beg + 1)));
		beg = end + 1;
	}
    return output;
}

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

#endif
