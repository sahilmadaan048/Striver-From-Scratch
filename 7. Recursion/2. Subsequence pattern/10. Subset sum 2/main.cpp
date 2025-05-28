// https://leetcode.com/problems/subsets-ii/description/

// https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/

class Solution {
      void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, curr, ans);
        return ans;        
   }
};