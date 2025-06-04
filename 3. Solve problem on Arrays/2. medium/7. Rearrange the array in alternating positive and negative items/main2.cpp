// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(nums[i] < 0) {
                ans[neg] = nums[i];
                neg+=2;
            } else {
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};

/*

Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.

Space Complexity:  O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.

*/