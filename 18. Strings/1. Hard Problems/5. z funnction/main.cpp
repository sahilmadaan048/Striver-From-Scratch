// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = needle.size();
        int n2 = haystack.size();

        for (int i = 0; i <= n2 - n1; i++) {  // Corrected condition
            if (haystack.substr(i, n1) == needle) {
                return i;
            }
        }
        return -1;
    }
};
