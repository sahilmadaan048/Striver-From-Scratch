// https://leetcode.com/problems/house-robber-ii/description/

// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/

class Solution {
    int solve(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = arr[0];
        int prev1 = max(arr[0], arr[1]);
        int curr;

        for (int i = 2; i < n; i++) {
            curr = max(prev1, arr[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> arr1(arr.begin() + 1, arr.end());      
        vector<int> arr2(arr.begin(), arr.end() - 1);      
        return max(solve(arr1), solve(arr2));
    }
};
