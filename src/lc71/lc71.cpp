#include "lc.h"

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() || path[0] != '/')
            return "/";
        stack<string> tmp;
        int len = path.size();
        for (int i = 0; i < len; )
        {
            int idx1 = i;
            while (idx1 < len && path[idx1] == '/') idx1++;
            if (idx1 == len)
                break;
            int idx2 = idx1;
            while (idx2 < len && path[idx2] != '/') idx2++;
            string str = path.substr(idx1, idx2 - idx1);
            if (str == ".")
            {
                i = idx2;
            }
            else if (str == "..")
            {
                if (!tmp.empty())
                    tmp.pop();
                i = idx2;
            }
            else
            {
                tmp.push(str);
                i = idx2;
            }
        }
        string ret;
        while (!tmp.empty())
        {
            ret = "/" + tmp.top() + ret;
            tmp.pop();
        }
        if (ret.empty())
            ret = "/";
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string line;
    while (getline(cin, line)) {
        string path = stringToString(line);
        
        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}