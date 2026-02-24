class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> open, star;
        
        for(int i = 0; i < n; i++) {
            char c = s[i];
            
            if(c == '(') {
                open.push(i);
            }
            else if(c == '*') {
                star.push(i);
            }
            else {
                if(!open.empty()) {
                    open.pop();
                }
                else if(!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        while(!open.empty() && !star.empty()) {
            if(open.top() < star.top()) {
                open.pop();
                star.pop();
            } else {
                return false;
            }
        }
        
        return open.empty();
    }
};