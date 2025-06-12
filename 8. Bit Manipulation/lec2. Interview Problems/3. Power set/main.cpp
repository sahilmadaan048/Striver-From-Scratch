// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n; // 2^n subsets
        vector<vector<int>> result;

        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};
