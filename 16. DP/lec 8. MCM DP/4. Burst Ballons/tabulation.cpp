// https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/

// https://leetcode.com/problems/burst-balloons/


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                int maxCoins = 0;

                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1];
                    int extraCoins = dp[i][k - 1] + dp[k + 1][j];
                    maxCoins = max(maxCoins, coins + extraCoins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};


/*

Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

Space Complexity: O(N2), N2 for the dp array we are using.
*/