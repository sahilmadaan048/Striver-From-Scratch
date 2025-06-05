// https://leetcode.com/problems/majority-element-ii/description/

// https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int ele : nums) {
            mp[ele]++;
        }

        for (auto [num, count] : mp) {
            if (count > threshold) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
