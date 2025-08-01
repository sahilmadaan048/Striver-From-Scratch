// https://leetcode.com/problems/partition-array-for-maximum-sum/

// https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/

class Solution {
    int helper(int ind, vector<int>& num, int k, vector<int>& dp) {
        int n = num.size();
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + helper(j + 1, num, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[ind] = maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int>& num, int k) {
        int n = num.size();
        vector<int> dp(n, -1);
        return helper(0, num, k, dp);
    }
};


/*
Time Complexity: O(N*k)
Reason: There are a total of N states and for each state, we are running a loop from 0 to k.

Space Complexity: O(N) + Auxiliary stack space O(N)
Reason: First O(N) for the dp array we are using.

*/