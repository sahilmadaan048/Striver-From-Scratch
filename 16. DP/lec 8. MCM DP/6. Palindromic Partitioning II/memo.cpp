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
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        int partitions = minPartitions(0, n, s, dp);
        // count partitions and minus 1 for nmber of vuts
        return partitions - 1;
    }   
};

/*

Time Complexity: O(N2)
Reason: There are a total of N states and inside each state, a loop of size N(apparently) is running.

Space Complexity: O(N) + Auxiliary stack space O(N)
Reason: The first O(N) is for the dp array of size N.
*/