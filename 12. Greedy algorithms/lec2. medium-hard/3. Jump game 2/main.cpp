// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // No jumps needed if already at the end

        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};

