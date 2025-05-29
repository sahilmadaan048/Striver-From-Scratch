// https://leetcode.com/problems/longest-happy-prefix/description/

class Solution {
public:
    string longestPrefix(string s) {
        int pre = 0, suf = 1;
        vector<int> lps(s.length(), 0);
        while (suf < s.length()) {
            if (s[suf] == s[pre]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return s.substr(0, pre);
    }
};


//lps using kmp standard algo