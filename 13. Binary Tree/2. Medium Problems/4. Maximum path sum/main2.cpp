/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findMaxPathSum(TreeNode* root, int& maxi) {
        if (root == nullptr) return 0;
        int left = max(0, findMaxPathSum(root->left, maxi));
        int right = max(0, findMaxPathSum(root->right, maxi));

        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findMaxPathSum(root, maxi);

        return maxi;   
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

/*

Time Complexity: O(N), each node is processed once in DFS Traversal.
Space Complexity: O(H), auxiliary stack space, where H is height of Binary Tree.

*/