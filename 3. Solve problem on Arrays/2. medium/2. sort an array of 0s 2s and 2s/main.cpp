// https://leetcode.com/problems/sort-colors/description/

// https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/

//first approach is by sorting n log n time

//second approach is by keepeing a count of the elements in the array n + n time

// This problem is a variation of the popular Dutch National flag algorithm. 
// o(n) time and o(!) space

// 0..low-1 is 0
// low mid-1 is 1
// mid to n-1 is 2

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int low = 0, mid = 0;
            int high = n-1;
            while(mid<=high) {
                if(nums[mid] == 0) {
                    swap(nums[low], nums[mid]);
                    mid++;
                    low++;
                }
                else if(nums[mid] == 1) {
                    mid++;
                } 
                else if(nums[mid] == 2) {
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
            return ;
        }
    };