// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int i = 0, ans = 0;

        for(int j = 0; j < n; j++) {
            if(freq[nums[j]] == 0) k--;  
            freq[nums[j]]++;

            while(k < 0) {
                freq[nums[i]]--;
                if(freq[nums[i]] == 0) k++;
                i++;
            }

            ans += j - i + 1; 
        }

        return ans;
    }
};
