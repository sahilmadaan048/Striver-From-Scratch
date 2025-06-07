// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// https://takeuforward.org/data-structure/last-occurrence-in-a-sorted-array/

class Solution {
    int lowerBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        int end = upperBound(nums, target);
        return {start, end};
    }
};
