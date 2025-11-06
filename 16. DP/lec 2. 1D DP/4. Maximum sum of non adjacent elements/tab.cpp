// https://leetcode.com/problems/house-robber/description/

// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumNonAdjacentSum(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];

        vector<int> dp(n);

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

int main() {
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}

/*
Time Complexity: O(N), every element of array is processed once.
Space Complexity: O(N), extra space used to store DP array.
*/