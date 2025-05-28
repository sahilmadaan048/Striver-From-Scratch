// https://leetcode.com/problems/combination-sum-ii/description/

// https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/

class Solution {
    void generate(int start, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int curr, int target) {
        if(curr == target) {
            ans.push_back(temp);            
            return;
        }
        if(curr > target) return;

        for(int i = start; i < n; ++i) {
            // Skip duplicates
            if(i > start && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            generate(i + 1, n, nums, temp, ans, curr + nums[i], target); // i + 1 to avoid reuse
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Important for skipping duplicates
        vector<vector<int>> ans;
        vector<int> temp;
        generate(0, n, nums, temp, ans, 0, target);
        return ans;
    }
};
