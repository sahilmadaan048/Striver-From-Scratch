/*

Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.


Examples:
Input : nums = [1, 2, 3, 4, 5] , k = 8

Output : Yes

Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Input : nums = [4, 3, 9, 2] , k = 10

Output : No

Explanation : No subsequence can sum up to 10.

*/


class Solution {
    bool check(vector<int>& nums, int ind, int curr, int k, int n) {
        if (ind == n) {
            return curr == k;
        }

        // Either take the current element (add it to curr)
        bool ans1 = check(nums, ind + 1, curr + nums[ind], k, n);

        // Or don't take it
        bool ans2 = check(nums, ind + 1, curr, k, n);

        return ans1 || ans2;
    }

public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n = nums.size();
        return check(nums, 0, 0, k, n);
    }
};
