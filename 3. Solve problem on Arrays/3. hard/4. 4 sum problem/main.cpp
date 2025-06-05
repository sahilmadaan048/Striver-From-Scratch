// https://leetcode.com/problems/4sum/

// https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans; // Early return if there are less than 4 numbers

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j

                int left = j + 1, right = n - 1;
                long long restsum = target - (long long)nums[i] - (long long)nums[j];

                while (left < right) {
                    long long sum = nums[left] + nums[right];
                    if (sum == restsum) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates for left
                        while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates for right
                        left++;
                        right--;
                    } else if (sum < restsum) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
