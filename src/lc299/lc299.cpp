#include "lc.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> secret_map;
        int len = secret.size();
        for (int i = 0; i < len; ++i)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
                secret_map[secret[i]]++;
        }
        for (int i = 0; i < len; ++i)
        {
            if (guess[i] == secret[i])  continue;
            auto iter = secret_map.find(guess[i]);
            if (iter != secret_map.end())
            {
                if (--(iter->second) >= 0)
                {
                    cows++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(int argc, char const *argv[])
{
	string line;
	while (getline(cin, line))
	{
		string secret, guess;
		walkString(secret, line);
		getline(cin, line);
		walkString(guess, line);
		cout << toString(Solution().getHint(secret, guess)) << endl;
	}
	return 0;
}