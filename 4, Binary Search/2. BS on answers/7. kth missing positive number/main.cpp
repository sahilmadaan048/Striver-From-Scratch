// https://leetcode.com/problems/kth-missing-positive-number/

// https://takeuforward.org/arrays/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(arr[i] <= k) {
                k++;
            } else break;
        }
        return k;
    }
};