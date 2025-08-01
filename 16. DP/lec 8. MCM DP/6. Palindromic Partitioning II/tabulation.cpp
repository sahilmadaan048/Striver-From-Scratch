// https://leetcode.com/problems/palindrome-partitioning-ii/description/

// https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/

class Solution {
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minPartitions(int i, int n, string & s, vector<int>& dp) {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j=i; j<n; j++) {
            if(isPalindrome(i, j, s)) {
                int cost = 1 + minPartitions(j+1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] =  minCost;
    }
public:
    int minCut(string str) {
        int n = str.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Initialize the last element to 0.

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, str)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }   
};


/*

Time Complexity: O(N2)
Reason: There are a total of N states and inside each state a loop of size N(apparently) is running.

Space Complexity: O(N)
Reason: O(N) is for the dp array we have used.

*/