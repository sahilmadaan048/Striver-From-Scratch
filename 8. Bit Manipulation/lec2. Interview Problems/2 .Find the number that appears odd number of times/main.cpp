// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int x = 0;

        for(auto ele: nums) x ^= ele;

        return x;
    }   
};