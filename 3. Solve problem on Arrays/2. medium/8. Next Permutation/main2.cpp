// Brute Force: Finding all possible permutations. 

// Approach :

// Step 1: Find all possible permutations of elements present and store them.

// Step 2: Search input from all possible permutations.

// Step 3: Print the next permutation present right after it.

// For reference of how to find all possible permutations, follow up https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s. This video shows for distinct elements but code works for duplicates too.

// Complexity Analysis
// For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array. Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).

// Space Complexity :

// Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).

class Solution {
public:
    vector<vector<int>> perms;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current) {
        if (current.size() == nums.size()) {
            perms.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            // Skip duplicates at the same depth
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current);
            current.pop_back();
            used[i] = false;
        }
    }

    void nextPermutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort to handle duplicates
        vector<bool> used(nums.size(), false);
        vector<int> current;

        backtrack(nums, used, current);  // Step 2: Generate unique permutations
        sort(perms.begin(), perms.end());

        for (int i = 0; i < perms.size(); ++i) {
            if (perms[i] == nums) {
                if (i + 1 < perms.size()) {
                    nums = perms[i + 1];
                } else {
                    nums = perms[0];  // Wrap around
                }
                return;
            }
        }
    }
};
