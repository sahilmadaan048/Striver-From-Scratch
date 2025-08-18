// https://www.geeksforgeeks.org/dsa/postfix-prefix-conversion/

// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

// User function Template for C++

class Solution {
    public: 

    bool alphanum(char c) {
        return ((c>='a' and c<='z') || (c>='A' and c<='Z') || (c>='0' and c<='9'));
    }
    
    
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        
        for(auto z: post_exp) {
            if(alphanum(z)) {
                string p = "";
                p += z;
                st.push(p);
            }else {
                string temp = "";
                temp += z;
                
                string t1 = st.top();
                st.pop();
                
                string t2 = st.top();
                st.pop();
                
                temp += t2;
                temp += t1;
                
                st.push(temp);
            }
        }
        
        return st.top();
    }
};