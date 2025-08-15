// https://leetcode.com/problems/max-consecutive-ones-iii/description/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int temp = k;
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n) {
            int ele = nums[j];
            // flip xeroes
            if(ele == 0) temp--;
            //recover exceess flipped zeroes
            while(temp < 0) {
                if(nums[i] == 0) temp++;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};


