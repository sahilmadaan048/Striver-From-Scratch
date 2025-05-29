// https://leetcode.com/problems/count-palindromic-subsequences/

class Solution {
public:
    bool isPalindrome(string& s) {
        return s[0] == s[4] && s[1] == s[3];
    }

    int countPalindromes(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        for (int m = l + 1; m < n; ++m) {
                            string sub = "";
                            sub += s[i];
                            sub += s[j];
                            sub += s[k];
                            sub += s[l];
                            sub += s[m];
                            if (isPalindrome(sub)) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
