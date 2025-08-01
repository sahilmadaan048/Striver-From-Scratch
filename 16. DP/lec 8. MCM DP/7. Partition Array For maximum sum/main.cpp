// https://leetcode.com/problems/partition-array-for-maximum-sum/

// https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/



class Solution {
    int helper(int ind, vector<int>& num, int k) {
        int n = num.size();
        if (ind == n) return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + helper(j + 1, num, k);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int>& num, int k) {
        return helper(0, num, k);
    }
};


/*
Time Complexity: Exponential
*/