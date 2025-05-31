// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cnt(n, 1);

        // Left to right pass
        for(int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cnt[i] = cnt[i - 1] + 1;
            }
        }

        // Right to left pass
        for(int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
            }
        }

        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
