// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution {
    int cal(string &s) {
        int maxi = 0, mini = INT_MAX;
        unordered_map<char, int> mp;

        for (char ch : s) mp[ch]++;

        for (auto &[ch, freq] : mp) {
            maxi = max(maxi, freq);
            mini = min(mini, freq);
        }

        return maxi - mini;
    }

public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                ans += cal(temp);
            }
        }

        return ans;
    }
};
