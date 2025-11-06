// https://leetcode.com/problems/house-robber/description/

// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        if (nums.empty()) return 0;

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int include = nums[i] + prev2;

            int exclude = prev;

            int curr = max(include, exclude);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    Solution obj;
    cout << obj.maxSum(arr) << endl;
    return 0;
}

/*
Time Complexity: O(N), every element of array is processed once.
Space Complexity: O(1) , only constant variables are used.
*/