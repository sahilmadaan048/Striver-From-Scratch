// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// https://leetcode.com/problems/maximum-units-on-a-truck/solutions/6786930/c-clear-and-efficient-solution-beats-100/

// https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>> vec;
        
        for(int i=0;i<val.size();i++) {
            vec.push_back({val[i], wt[i]});
        }
        
        sort(vec.begin(),vec.end(),[&](auto a, auto b){
            return (double(a.first)/double(a.second)) > (double(b.first)/double(b.second));
        });
        
        double ans = 0;
        
        for(auto ele : vec) {
            if(capacity >= ele.second) {
                ans += ele.first;
                capacity -= ele.second;
            } else {
                double perGm = double(ele.first) / double(ele.second);
                ans += capacity * perGm;
                break;
            }
        }
        
        return ans;
    }
};

/*

Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

Space Complexity: O(1), no additional data structure has been used


*/