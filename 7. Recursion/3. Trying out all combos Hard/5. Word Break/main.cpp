// https://leetcode.com/problems/word-break/description/

class Solution {
    unordered_set<string> dict;
    unordered_map<int, bool> memo;

    bool check(string &s, int start) {
        if (start == s.size()) return true;
        if (memo.count(start)) return memo[start];

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && check(s, end)) {
                return memo[start] = true;
            }
        }

        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return check(s, 0);
    }
};
