// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(n+1, 0);

        count[0] = 1;
        int ans = 0, t= 0;
        for(auto v: nums) {
            t += (v & 1);
            if(t >= k) {
                ans += count[t - k];
            }
            count[t]++;
        }   
        return ans;
    }
};