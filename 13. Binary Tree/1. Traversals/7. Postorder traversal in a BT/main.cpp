// https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/


// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    void inorder(TreeNode* root, vector<int> &arr){
        // If the current node is NULL
        // (base case for recursion), return
        if(root == nullptr){
            return;
        }
        // Recursively traverse the left subtree
        inorder(root->left, arr);
        // Recursively traverse 
        // the right subtree
        inorder(root->right, arr);
        // Push the current node's
        // value into the vector
        arr.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;   
    }
};