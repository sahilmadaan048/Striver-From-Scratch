// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1; // empty prefix sum

        int currSum = 0;
        int ans = 0;

        for(int num : nums) {
            currSum += num;

            // number of subarrays ending here with sum == goal
            if(prefixCount.find(currSum - goal) != prefixCount.end()) {
                ans += prefixCount[currSum - goal];
            }

            // update prefix sums count
            prefixCount[currSum]++;
        }

        return ans;
    }
};
