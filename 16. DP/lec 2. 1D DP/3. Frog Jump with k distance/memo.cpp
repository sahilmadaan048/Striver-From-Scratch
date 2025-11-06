// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/

#include <bits/stdc++.h>
using namespace std;

int solveUtil(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
        return dp[ind];

    int mini = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mini = min(mini, jump);
        }
    }

    return dp[ind] = mini;
}

int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);
    cout << solve(n, height, k) << endl;
    return 0;
}

/*

Time Complexity: O(N *K)

Reason: The overlapping subproblems will return the answer in constant time. Therefore the total number of new subproblems we solve is ‘n’. At every new subproblem, we are running another loop for K times. Hence total time complexity is O(N * K).

Space Complexity: O(N)

Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

*/
