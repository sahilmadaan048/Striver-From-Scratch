// https://leetcode.com/problems/maximum-units-on-a-truck/description/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int total = 0;
        for(int i = 0, n = boxTypes.size(); i < n; ++i){
            int val = boxTypes[i][0];
            if(val < truckSize){
                total += (val * boxTypes[i][1]);
                truckSize -= val;
            }
            else return total + truckSize * boxTypes[i][1];
        }
        return total;
    }
};