// https://takeuforward.org/Greedy/jump-game-i

// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i=0; i<n; i++) {
            if(i > maxIndex) {
                // we cannnot move format
                return false;
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }
        
        return true;
    }
};


/*


Time Complexity: O(N) where N is the length of the input array. We iterate through the input array exactly once and at each element perform constant time operations.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.


*/