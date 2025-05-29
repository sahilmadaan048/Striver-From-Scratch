// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        for(int i=n-1; i>=0; i--) {
            if(isPalindrome(0, i, s)) {
                string temp = s.substr(i+1);
                reverse(temp.begin(), temp.end());
                return temp + s;
            }
        }
        return s;
    }
};