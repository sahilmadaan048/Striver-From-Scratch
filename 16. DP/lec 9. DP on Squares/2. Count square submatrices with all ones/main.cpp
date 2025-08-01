// https://takeuforward.org/data-structure/count-square-submatrices-with-all-1s-dp-on-rectangles-dp-56/

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();  
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    sum += dp[i][j];
                }
            }
        }

        return sum;
    }
};


/*

Time Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
Reason: We are basically traversing a 2D matrix with N rows and M columns.

Space Complexity: O(N*M), where N = total no. of rows and M = total no. of columns
Reason: We are using a 2D dp array with N rows and M columns.
*/