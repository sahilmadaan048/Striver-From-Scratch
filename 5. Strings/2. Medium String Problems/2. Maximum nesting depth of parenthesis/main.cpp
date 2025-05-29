// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxi = 0;
        int depth = 0;
        for(int i=0; i<n ; i++) {
            if(s[i] == '(') {
                depth++;
                maxi = max(maxi, depth);
            } else if(s[i] == ')') {
                depth--;
                maxi = max(maxi, depth);
            }
        }
        return maxi;
    }
};

//it is correct now