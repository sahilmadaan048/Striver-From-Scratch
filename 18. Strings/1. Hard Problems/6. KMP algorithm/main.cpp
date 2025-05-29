// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    // Build LPS array for needle
    vector<int> buildLPS(const string& needle) {
        int m = needle.size();
        vector<int> lps(m, 0);
        int len = 0; // length of previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0; // edge case: empty needle

        vector<int> lps = buildLPS(needle);

        int i = 0; // index for haystack
        int j = 0; // index for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == m) {
                    return i - j; // match found
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1]; // use LPS to avoid rechecking
                } else {
                    i++;
                }
            }
        }

        return -1; // no match found
    }
};
