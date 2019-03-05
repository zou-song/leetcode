#include "lc.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int width = 0;
        vector<string> ret;
        int len = words.size();
        for (int i = 0; i < len; ++i)
        {
            if (width + words[i].size() + 1 > maxWidth)
            {
                int cnt = line.size();
                int wdwidth = width - (cnt - 1);
                int spwidth = maxWidth - wdwidth;
                if (cnt == 1)
                {
                    string str = line[0] + string(spwidth, ' ');
                    ret.push_back(str);
                }
                else
                {
                    int avgspwidth = spwidth / (cnt - 1);
                    int adtspwidth = spwidth - (cnt - 1) * avgspwidth;
                    string str;
                    for (int j = 0; j < cnt; ++j)
                    {
                        str = str + line[j];
                        if (adtspwidth-- > 0)
                            str += string((avgspwidth + 1), ' ');
                        else if (j != cnt - 1)
                            str += string(avgspwidth, ' ');
                    }
                    ret.push_back(str);
                }
                line.clear();
                width = 0;
            }
            line.push_back(words[i]);
            width += (1 + words[i].size());
        }
        if (!line.empty())
        {
            string str;
            int cnt = line.size();
            for (int i = 0; i < cnt; ++i)
            {
                str += line[i];
                if (i != cnt - 1)
                    str += ' ';
            }
            if (str.size() < maxWidth)
                str += string(maxWidth - str.size(), ' ');
            ret.push_back(str);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	string line;
	while (getline(cin, line))
	{
		vector<string> words;
		walkString(words, line);
		getline(cin, line);
		int maxWidth = 0;
		walkString(maxWidth, line);
		vector<string> output = Solution().fullJustify(words, maxWidth);
		cout << toString(output) << endl;
	}
	return 0;
}