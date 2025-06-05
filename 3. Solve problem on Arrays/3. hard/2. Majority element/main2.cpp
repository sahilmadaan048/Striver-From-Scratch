# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int, int> mp;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) mp[nums[i]] = i;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n; j++) {
  
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                int z = -nums[i] - nums[j];

                // Check if the third element exists in the map and is not one of the first two elements
                if (mp.find(z) != mp.end() && mp[z] > j) {
                    ans.push_back({nums[i], nums[j], z});
                }
            }
        }

        return ans;
    }
};

```