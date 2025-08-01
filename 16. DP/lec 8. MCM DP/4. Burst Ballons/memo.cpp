// https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/

// https://leetcode.com/problems/burst-balloons/

class Solution {
    int helper(int i, int j, vector<int>& nums, vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxCoins = INT_MIN;

        for(int k=i; k<=j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];

            int extraCoins = helper(i, k-1, nums, dp) + helper(k+1, j, nums, dp);

            maxCoins = max(maxCoins, coins + extraCoins);
        }

        return dp[i][j] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return helper(1, n, nums, dp);
    }
};

/*
Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

Space Complexity: O(N2) + Auxiliary stack space of O(N), N2 for the dp array we are using. 

*/