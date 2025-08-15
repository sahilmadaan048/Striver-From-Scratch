// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/1735819918/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        int ans = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            freq[s[j]]++;

            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
                freq[s[i]]--;
                i++;
            }

            ans += i;
        }

        return ans;
    }
};