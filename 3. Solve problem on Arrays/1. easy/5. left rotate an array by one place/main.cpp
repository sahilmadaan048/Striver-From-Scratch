// https://takeuforward.org/data-structure/left-rotate-the-array-by-one/

// https://leetcode.com/problems/rotate-array/description/

class Solution {
    void reverse(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; 
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};
