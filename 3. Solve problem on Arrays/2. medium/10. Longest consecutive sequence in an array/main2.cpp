class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = INT_MIN;

        int n = nums.size();
        if (n == 0) return 0;
        int ans = 1;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            if (ele - 1 == last) {
                cnt += 1;
                last = nums[i];
            }
            else if (nums[i] != last) {
                cnt = 1;
                last = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};


/*
Time Complexity: O(NlogN) + O(N), N = size of the given array.
Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

Space Complexity: O(1), as we are not using any extra space to solve this problem.


*/