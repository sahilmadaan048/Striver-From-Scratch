// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        int n = s.size();
        stack<char> st;
        string res;
        
        for(int i=0; i<n; i++) {
            char c = s[i];
                
            if((c <= 'Z' and c >= 'A') || (c <= 'z' and c >= 'a') || (c <= '9' and c >= '0')) {
                res += c;
                
                while(!st.empty() and st.top() == ')') {
                    res += st.top();
                    st.pop();
                }
                
                if(!st.empty()) {
                    res += st.top();
                    st.pop();
                }
            }
            
            else {
                res += '(';
                st.push(')');
                st.push(c);
            }
        }
        
        return res;
    }
};