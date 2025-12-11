// https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;

        if (ind == 0) return arr[0] == target;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        bool taken = false;
        if (arr[ind] <= target) {
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = notTaken || taken;
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}


/*

Time Complexity: O(N*K),There are N*K states therefore at max ‘N*K’ new problems will be solved.

Space Complexity: O(N*K) + O(N),We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

*/