// https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/

// https://leetcode.com/problems/unique-paths/submissions/1847908811/

#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int func(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 or j == 0) return 1;

        if(i < 0 or j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = func(i-1, j, dp);
        int left = func(i, j-1, dp);
        
        return dp[i][j] = up + left;
    }
    public: 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m-1, n-1, dp);
    }
};

int main() {
    int m = 3;
    int n = 2;

    Solution sol;

    cout << "Number of ways: " << sol.uniqueWays(m, n) << endl;
}

/*

Complexity Analysis
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are filling up a 2D DP array of size m x n, and each cell takes constant time to compute.

Space Complexity: O(m * n), due to the storage of the DP array which keeps track of the number of unique paths to each cell in the grid.

*/