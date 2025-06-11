// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// https://takeuforward.org/arrays/find-the-smallest-divisor-given-a-threshold/

    class Solution {
    int sumByD(vector<int>& nums, int mid) {
        int count = 0;
        for (auto ele : nums) {
            count += ceil((double)ele / mid);
        }
        return count;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (sumByD(nums, mid) <= threshold) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
