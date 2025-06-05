// https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/

/*

Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> mpp;
    int sum = 0;

    for(int i=0; i<a.size(); i++) {
        sum += a[i];

        if(sum == 0) {
            maxLen = maxLen + 1;
        } else if(mpp.find(sum) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;
    return 0;
}


/*

Time Complexity: O(N^2) as we have two loops for traversal

Space Complexity: O(1) as we aren’t using any extra space.

*/