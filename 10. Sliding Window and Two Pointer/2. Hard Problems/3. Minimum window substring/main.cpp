// https://leetcode.com/problems/minimum-window-substring/submissions/1735854030/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(n == 0) return "";

        unordered_map<char,int> target;
        for(char c : t) target[c]++;

        unordered_map<char,int> window;
        int i = 0, j = 0;
        int required = target.size();
        int formed = 0; 

        int minLen = INT_MAX;
        int start = 0;

        while(j < m) {
            char c = s[j];
            window[c]++;

            if(target.count(c) && window[c] == target[c]) formed++;

            while(i <= j && formed == required) {
                // update minimum window
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                // shrink from left
                char leftChar = s[i];
                window[leftChar]--;
                if(target.count(leftChar) && window[leftChar] < target[leftChar]) {
                    formed--;
                }
                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
