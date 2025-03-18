class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            int count = 0; // Count of breaks in sorting
            
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[i-1]) {
                    count++; // Found an out-of-order pair
                }
            }
            
            // Also check the circular case (last element vs first element)
            if(nums[n-1] > nums[0]) {
                count++;
            }
            
            // If there is at most one break, it's a rotated sorted array
            return count <= 1;
        }
    };
    