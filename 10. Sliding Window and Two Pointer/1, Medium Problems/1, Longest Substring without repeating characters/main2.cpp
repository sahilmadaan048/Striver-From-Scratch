// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int i = 0, j = 0, maxi = 0;

        while (j < n) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};
