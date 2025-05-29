// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<char> st;
        string temp = ""; // to store characters of current primitive

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (!st.empty()) temp += '('; // not outermost
                st.push('(');
            } else {
                st.pop();
                if (!st.empty()) temp += ')'; // not outermost
                else {
                    ans += temp; // completed one primitive
                    temp = "";   // reset for next primitive
                }
            }
        }

        return ans;
    }
};
