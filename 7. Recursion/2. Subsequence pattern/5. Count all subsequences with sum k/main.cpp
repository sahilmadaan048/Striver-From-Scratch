/*

Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Examples:
Input : nums = [4, 9, 2, 5, 1] , k = 10

Output : 2

Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

Output : 3

Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

*/

// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2

class Solution{
    int generate(int start, int n, vector<int>& nums, int curr, int target) {
        if(start == n and curr == target) {
            return 1;
        } else if(start == n) {
            return 0;
        }

        //either take it
        int ans1 = generate(start+1, n, nums, curr + nums[start], target);
        //or dont take it
        int ans2 = generate(start+1, n, nums, curr, target);

        return ans1 + ans2;
    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        // int ans = 0;
        int n = nums.size();
        // int ans = 0 ;
        int ans = generate(0, n,  nums, 0, k);
        return ans;
    }
};