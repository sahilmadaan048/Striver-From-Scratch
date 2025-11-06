// memoisation approach

#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}

int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<f(n,dp);
  return 0;
}


// Output: 5

// Time Complexity: O(N)

// Reason: The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

// Space Complexity: O(N)

// Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)