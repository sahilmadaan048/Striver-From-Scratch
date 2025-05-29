// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++) {
            if(s[i] == ')' and !st.empty() and  st.top() == '(') {
                st.pop();
            }
            else st.push(s[i]);
        }

        return st.size();
    }
};