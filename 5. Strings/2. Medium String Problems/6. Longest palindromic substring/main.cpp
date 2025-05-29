// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        int n = s.size();

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd-length
            expand(i, i + 1); // Even-length
        }

        return s.substr(start, maxLen);
    }
};
