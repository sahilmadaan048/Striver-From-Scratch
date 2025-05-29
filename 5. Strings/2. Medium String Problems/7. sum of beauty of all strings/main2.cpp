class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxi = max(maxi, f);
                        mini = min(mini, f);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
