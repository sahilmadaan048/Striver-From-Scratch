class Solution {
    unordered_set<string> dict;

    bool check(string &s, int start) {
        if (start == s.size()) return true;

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && check(s, end)) {
                return true;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return check(s, 0);
    }
};
