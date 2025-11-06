// https://leetcode.com/problems/house-robber/description/

// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {

        if (i < 0)
            return 0;

        if (i == 0)
            return arr[0];

        if (dp[i] != -1)
            return dp[i];

        int pick = arr[i] + solve(arr, i - 2, dp);

        int notPick = solve(arr, i - 1, dp);

        return dp[i] = max(pick, notPick);
    }

    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();

        // DP array initialized with -1
        vector<int> dp(n, -1);

        // Start solving from last index
        return solve(arr, n - 1, dp);
    }
};

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;

    // Output the result
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}

/*
Time Complexity: O(N), where N = total no. of elements in array. The overlapping subproblems will return the answer in constant time O(1).
Space Complexity: O(N+N), extra space used for memoization and auxiliary stack space.
*/