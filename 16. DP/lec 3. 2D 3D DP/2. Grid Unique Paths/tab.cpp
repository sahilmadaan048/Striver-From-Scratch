#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int m, int n, vector<vector<int>>& dp){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }

            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m, n, dp);
    }
};
int main() {
    int m = 3;
    int n = 2;
    Solution sol;
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;
    return 0;
}

/*
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), as we are using a 2D array to store the results of subproblems. However, we can optimize this to O(n) by using a 1D array and updating it in place.


*/