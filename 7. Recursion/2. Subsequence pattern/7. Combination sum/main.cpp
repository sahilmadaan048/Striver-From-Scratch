// https://leetcode.com/problems/combination-sum/description/
// https://takeuforward.org/data-structure/combination-sum-1/

class Solution {
    void generate(int start, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int curr, int target) {
        if(curr == target) {
            ans.push_back(temp);            
            return;
        }
        if(curr > target || start == n) return;

        // take the element
        temp.push_back(nums[start]);
        generate(start, n, nums, temp, ans, curr + nums[start], target);
        temp.pop_back(); // backtrack

        // don't take the element
        generate(start + 1, n, nums, temp, ans, curr, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        generate(0, n, nums, temp, ans, 0, target);
        return ans;
    }
};

