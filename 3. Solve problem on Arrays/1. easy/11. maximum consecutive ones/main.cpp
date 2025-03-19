// https://leetcode.com/problems/max-consecutive-ones/


// 

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int n = nums.size();
            int res = 0;
            int i = 0;
            while(i<n) {
                //lets make it point to the fiurst 1
                if(nums[i] == 0) {
                    i++;
                }
                //now we are pointing to the first 1
                //now count the number of ones and then update  it
                int cnt = 0;
                while(i<n && nums[i] == 1){
                    i++;
                    cnt += 1;
                }
                res = max(res, cnt);
            }
            return res;
        }
    };