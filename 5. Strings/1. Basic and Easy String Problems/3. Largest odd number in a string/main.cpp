// https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        // find the last index where the charavyer is a odd dogot
        // int cnt = 0;
        int n = num.size();
        char ch = '!';
        int idx = -1;
        for(int i=0; i<n; i++) {
            if((num[i] - '0') % 2 == 1) {
                ch = num[i];
                idx = i;
            }    
        }

        if(ch == '!') return "";
        return num.substr(0, idx + 1);
    }
};