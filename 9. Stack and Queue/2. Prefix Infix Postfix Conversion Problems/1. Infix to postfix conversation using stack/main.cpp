// https://takeuforward.org/data-structure/infix-to-postfix/

// https://www.geeksforgeeks.org/dsa/convert-infix-expression-to-postfix-expression/

// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution {
    
    int prec(char c) {
      if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;
    }

  public:
    string infixToPostfix(string& s) {
        
  stack < char > st; //For stack operations, we are using C++ built in stack
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }
  
  return result;
    }   
};

