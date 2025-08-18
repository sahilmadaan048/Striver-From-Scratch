// https://www.geeksforgeeks.org/dsa/prefix-postfix-conversion/

// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> stk;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                string str(1, s[i]);
                stk.push(str);
            }
            else
            {
                string firstOperand = stk.top();
                stk.pop();
                string secondOperand = stk.top();
                stk.pop();
                string temp = firstOperand + secondOperand + s[i];
                stk.push(temp);
            }
        }
        return stk.top();
    }
};
