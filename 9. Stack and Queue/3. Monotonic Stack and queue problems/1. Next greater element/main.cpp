// https://leetcode.com/problems/next-greater-element-i/description/

// https://takeuforward.org/data-structure/next-greater-element-using-stack/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> values;
        int m = nums1.size();
        vector<int> ans(m);
        int n = nums2.size();

        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                values[nums2[i]] = -1;
            }
            else {
                values[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i=0; i<m; i++) {
            ans[i] = values[nums1[i]];
        }

        return ans;
    }
};