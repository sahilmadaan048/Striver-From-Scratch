// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        long long count = 0;
        int length = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                length++;
            } else {
                count = (count + 1LL * length * (length + 1) / 2) % MOD;
                length = 1;
            }
        }

        // Add the last segment
        count = (count + 1LL * length * (length + 1) / 2) % MOD;

        return count;
    }
};
