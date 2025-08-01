// https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/

// https://leetcode.com/problems/burst-balloons/


class Solution {
    int helper(int i, int j, vector<int>& nums) {
        if(i > j) return 0;

        int maxCoins = INT_MIN;

        for(int k=i; k<=j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];

            int extraCoins = helper(i, k-1, nums) + helper(k+1, j, nums);

            maxCoins = max(maxCoins, coins + extraCoins);
        }

        return maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return helper(1, n, nums);
    }
};
/*
Time Complexity: Exponential

*/