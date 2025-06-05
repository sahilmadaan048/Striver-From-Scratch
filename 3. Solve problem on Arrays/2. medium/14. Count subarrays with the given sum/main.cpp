// https://leetcode.com/problems/subarray-sum-equals-k/description/

// https://takeuforward.org/arrays/count-subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; // base case: for subarrays that start from index 0

        for (auto ele : nums) {
            sum += ele;

            // Check if there is a prefix sum that satisfies the condition
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};
