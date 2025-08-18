// https://takeuforward.org/data-structure/check-for-balanced-parentheses/

// https://leetcode.com/problems/valid-parentheses/description/


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;

        for(auto ele: s) {
            char ch = ele;  
            if(ele == '(' || ele == '[' or ele == '{') st.push(ele);
            else {
                if(st.empty()) return false;
                if((ele == ')' && st.top() != '(') ||
                   (ele == ']' && st.top() != '[') ||
                   (ele == '}' && st.top() != '{')) {
                    return false; // mismatch
                }
                st.pop();
            }
        }

        return st.empty();
    }
};