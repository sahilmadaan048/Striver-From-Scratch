// https://takeuforward.org/arrays/capacity-to-ship-packages-within-d-days/

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {

    int calDays(vector<int>& weights, int mid) {
        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++) {
            if(load + weights[i] > mid) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int numDays = calDays(weights, mid);

            if(numDays <= days) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};