// https://leetcode.com/problems/jump-game-iii/submissions/1929618454/

class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        bool flag = false;
        int n = nums.size();

        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            
            if(nums[idx] == 0) return true;
            if(nums[idx] < 0) continue;   
            
            int jump = nums[idx];
            nums[idx] = -nums[idx];      
            
            if(idx + jump < n)
                q.push(idx + jump);
            
            if(idx - jump >= 0)
                q.push(idx - jump);
        }
        return false;
    }
};

/*
Time complexity:
O(n)

Each index is visited at most once.

Space complexity:
O(n)

In worst case, queue may hold up to n elements.
*/