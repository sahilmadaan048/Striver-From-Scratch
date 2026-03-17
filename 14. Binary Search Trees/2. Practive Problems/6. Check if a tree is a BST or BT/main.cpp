// https://takeuforward.org/data-structure/check-if-binary-tree-is-bst

// https://leetcode.com/problems/validate-binary-search-tree/description/

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

    bool check(TreeNode* root, long mini, long maxi) {
        if(!root) return true;
        if(root->val <= mini or root->val >= maxi) return false;
        return check(root->left, mini, root->val) and check(root->right, root->val, maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);   
    }
};

/*

Complexity Analysis
Time Complexity: O(N) , for traversing N nodes.

Space Complexity: O(N) , auxiallary stack space.

*/