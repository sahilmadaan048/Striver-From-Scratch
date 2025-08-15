// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(int val : cardPoints) total += val;

        if(k == n) return total; // take all cards

        int windowSize = n - k;
        int windowSum = 0;
        for(int i = 0; i < windowSize; i++) windowSum += cardPoints[i];

        int minWindow = windowSum;

        for(int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindow = min(minWindow, windowSum);
        }

        return total - minWindow;
    }
};
