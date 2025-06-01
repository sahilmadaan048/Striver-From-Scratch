// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

// https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixIndex;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If subarray from 0 to i has sum k
            if (sum == k) {
                maxLen = i + 1;
            }

            // If sum - k was seen before, then a subarray summing to k exists
            if (prefixIndex.find(sum - k) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[sum - k]);
            }

            // Store the first occurrence of this sum
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};


/*

Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Note: To know more about maps, please refer to this: Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course.

Space Complexity: O(N) as we are using a map data structure.

*/