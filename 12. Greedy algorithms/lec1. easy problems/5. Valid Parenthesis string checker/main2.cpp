class Solution {
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }

private:
    bool dfs(const string& s, int index, int open) {
        if (open < 0) return false;  // Too many closing brackets
        if (index == s.size()) return open == 0;

        char ch = s[index];
        if (ch == '(') {
            return dfs(s, index + 1, open + 1);
        } else if (ch == ')') {
            return dfs(s, index + 1, open - 1);
        } else { // ch == '*'
            // Try '*'' as '(', ')', or ''
            return dfs(s, index + 1, open + 1) ||  // '*' → '('
                   dfs(s, index + 1, open - 1) ||  // '*' → ')'
                   dfs(s, index + 1, open);        // '*' → ''
        }
    }
};
