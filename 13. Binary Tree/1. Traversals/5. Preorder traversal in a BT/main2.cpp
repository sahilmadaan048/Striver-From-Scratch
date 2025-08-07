// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/

// https://www.youtube.com/watch?v=RlUu72JrOCQ

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

    void solve(TreeNode* root, vector<int> & ans) {
        if(root == nullptr) {
            return ;
        }
        ans.push_back(root->val);
        if(root->left) solve(root->left,  ans);
        if(root->right) solve(root->right, ans);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};