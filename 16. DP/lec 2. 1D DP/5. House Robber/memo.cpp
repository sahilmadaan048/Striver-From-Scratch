// https://leetcode.com/problems/house-robber-ii/description/

// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/

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
    
public:
    int rob(vector<int>& arr) {
        int n =  arr.size();
        vector<int> arr1;
        vector<int> arr2;
        
        if(n==1)
            return arr[0];
        
        for(int i=0; i<n; i++){
            
            if(i!=0) arr1.push_back(arr[i]);
            if(i!=n-1) arr2.push_back(arr[i]);
        }
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> dp1(n1, -1), dp2(n2, -1);
        long long int ans1 = solve(arr1, n1-1, dp1);
        long long int ans2 = solve(arr2, n2-1, dp2);
        return max(ans1, ans2);
    }
};