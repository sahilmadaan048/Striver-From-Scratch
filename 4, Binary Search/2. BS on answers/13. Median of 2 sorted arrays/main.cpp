class Solution {
    void merge(int n1, int n2, vector<int>& nums1, vector<int>& nums2, vector<int>& merged) {
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < n1) {
            merged.push_back(nums1[i++]);
        }
        while (j < n2) {
            merged.push_back(nums2[j++]);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> merged;
        merge(n1, n2, nums1, nums2, merged);

        int n = n1 + n2;
        if (n % 2 == 1) {
            return merged[n / 2];
        } 
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};
