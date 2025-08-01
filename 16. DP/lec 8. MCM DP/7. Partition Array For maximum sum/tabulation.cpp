// https://leetcode.com/problems/partition-array-for-maximum-sum/

// https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& num, int k) {
        int n = num.size();
        vector<int> dp(n + 1, 0);  // dp[i] = max sum we can get from index i to end

        for (int i = n - 1; i >= 0; i--) {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = i; j < min(i + k, n); j++) {
                len++;
                maxi = max(maxi, num[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }

            dp[i] = maxAns;
        }

        return dp[0];
    }
};



/*
Time Complexity: O(N*k)
Reason: There are a total of N states and for each state, we are running a loop from 0 to k.

Space Complexity: O(N)
Reason: O(N) for the dp array we are using.

*/