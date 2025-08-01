// https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/

// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{

    int dp[N][N];

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {

            int mini = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {

                int ans = dp[i][k] + dp[k+1][j] + arr[i - 1] * arr[k] * arr[j];

                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};

    int n = arr.size();

    cout << "The minimum number of operations is " << matrixMultiplication(arr, n);

    return 0;
}

/*

Output:

The minimum number of operations are 38000

Time Complexity: O(N*N*N)

Reason: There are N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

Space Complexity: O(N*N)

Reason: We are using a 2D array ( O(N*N)) space.

*/

/*

RULES:

1. copy the base cases
2. write down the changing parameters
3. copy the recurrence


*/