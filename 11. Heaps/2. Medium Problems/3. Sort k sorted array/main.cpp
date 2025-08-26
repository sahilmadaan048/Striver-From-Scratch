// https://takeuforward.org/plus/dsa/problems/merge-k-sorted-lists?tab=editorial

// https://www.geeksforgeeks.org/dsa/nearly-sorted-algorithm/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        
        int i = 0;
        for(i=k; i<n; i++) {
            pq.push(arr[i]);
            
            arr[i-k] = pq.top();
            pq.pop();
        }
        
        while(!pq.empty()) {
            arr[i-k] = pq.top();
            pq.pop();
            i++;
        }
        return ;
    }
};