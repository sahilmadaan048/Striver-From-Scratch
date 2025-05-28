// https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/

/*
Given an array nums of n integers.Return sum of all subsets of the array nums.



Output can be printed in any order.


Examples:
Input : nums = [2, 3]

Output : [0, 2, 3, 5]

Explanation :

When no elements is taken then Sum = 0.

When only 2 is taken then Sum = 2.

When only 3 is taken then Sum = 3.

When element 2 and 3 are taken then sum = 2+3 = 5.

Input : nums = [5, 2, 1]

Output : [0, 1, 2, 3, 5, 6, 7, 8]

Explanation :

When no elements is taken then Sum = 0.

When only 5 is taken then Sum = 5.

When only 2 is taken then Sum = 2.

When only 1 is taken then Sum = 1.

When element 2 and 1 are taken then sum = 2+1 = 3.

*/

class Solution {
    void generate(vector<int>& ans, vector<int>& nums, int n, int ind, int curr) {
        if (ind == n) {
            ans.push_back(curr);
            return;
        }

        // Pick the current element
        generate(ans, nums, n, ind + 1, curr + nums[ind]);

        // Do not pick the current element
        generate(ans, nums, n, ind + 1, curr);
    }

public:
    vector<int> subsetSums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        generate(ans, nums, n, 0, 0);
        return ans;
    }
};
