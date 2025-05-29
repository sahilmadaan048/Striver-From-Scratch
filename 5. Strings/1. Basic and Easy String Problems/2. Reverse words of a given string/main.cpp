// https://leetcode.com/problems/reverse-words-in-a-string/description/

// https://leetcode.com/problems/reverse-words-in-a-string/description/

// https://takeuforward.org/plus/dsa/problems/reverse-every-word-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        vector<string> res;

        while (ss >> temp) {
            res.push_back(temp);
        }

        string ans = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            ans += res[i];
            if (i != 0) ans += ' ';
        }

        return ans;
    }
};
