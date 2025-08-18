// https://www.geeksforgeeks.org/dsa/postfix-to-infix/

// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1


class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for(int i=0;i<exp.size();i++){
            if(isalnum(exp[i]))st.push(string(1,exp[i])); //converting char to string
            else{
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string c='('+b+exp[i]+a+')';
                st.push(c);
            }
        }
        return st.top();
    }
};