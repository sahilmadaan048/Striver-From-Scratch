// https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/

class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq; //a
        for (auto ele : nums) {
            pq.push(ele);
            if (pq.size() > k) {
                pq.pop(); 
            }
        }

        return pq.top();
    }
};
