//  https://www.geeksforgeeks.org/sort-a-stack-using-recursion/ -->


#include <iostream>
#include <stack>
using namespace std;

// Main function to sort a stack 
void sortStack(stack<int> &st) {
    
    // If stack is empty
    if (st.empty()) return;
    
    // Pop the top element 
    int top = st.top();
    st.pop();
    
    // Recursively sort the rest 
    // of the stack.
    sortStack(st);
    
    // Now, add the poppped element
    // into its correct sorted postion.
    stack<int> tmp;
    
    while (!st.empty() && st.top()>top) {
        tmp.push(st.top());
        st.pop();
    }
    
    // Push the popped value 
    st.push(top);
    
    // Now add the rest of values 
    // to the top.
    while (!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();
    }
}

int main(void) {
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sortStack(st);
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}