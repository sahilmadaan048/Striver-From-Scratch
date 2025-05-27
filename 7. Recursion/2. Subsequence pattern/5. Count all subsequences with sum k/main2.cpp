//making i


class Solution {
    int generate(int start, int n, vector<int>& nums, int curr, int target, int count) {
        if (start == n) {
            return (curr == target && count > 0) ? 1 : 0;
        }

        // either take it
        int ans1 = generate(start + 1, n, nums, curr + nums[start], target, count + 1);
        // or don't take it
        int ans2 = generate(start + 1, n, nums, curr, target, count);

        return ans1 + ans2;
    }

public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        int n = nums.size();
        return generate(0, n, nums, 0, k, 0);  // pass count = 0 initially
    }
};
