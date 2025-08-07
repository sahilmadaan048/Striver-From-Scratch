// https://leetcode.com/problems/binary-tree-inorder-traversal/

// https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/


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
public:

    void recursion(TreeNode *root, vector<int> &res){
        if(root == NULL) return;
        if(root != NULL) recursion(root -> left, res);
        res.push_back(root -> val);
        if(root != NULL) recursion(root -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        recursion(root, res);
        return res;
    }
};