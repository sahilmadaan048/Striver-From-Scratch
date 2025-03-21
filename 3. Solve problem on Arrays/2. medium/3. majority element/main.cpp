// https://leetcode.com/problems/majority-element/description/

// https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/

// brute force is o(n^2) loop inside loop tocheck the count of all the elements one after other

// 2nd approach use a map o (n log n)
// space will be o(n)

// best approach => moores voting algorithm

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            //moore voting algorithm
            
            int n = nums.size();
            int count = 0;
            int element; //iska coint nikalna hai
    
            for(int i=0; i<n; i++) {
                if(count == 0) {
                    count = 1;
                    element = nums[i];
                }
                else if(element == nums[i]) {
                    count++;
                } 
                else {
                    count--;
                }
            }
    
            int cnt = 0;
            for(auto ele: nums){
                if(ele == element) cnt++;
            }
    
            if(cnt > n/2) return element;
            return -1;
        }
    };
