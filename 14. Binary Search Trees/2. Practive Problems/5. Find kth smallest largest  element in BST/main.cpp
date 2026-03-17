// https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void traverse(TreeNode* root, vector<int> &inorder) {
        if(!root) return;
        if(root->left) traverse(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right) traverse(root->right, inorder);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int> inorder;
        traverse(root, inorder);
        return inorder[k-1];    
    }
};

/*

Complexity Analysis
Time Complexity: O(N), where N is the number of nodes in the BST. Because the code performs an in-order traversal of the BST, which requires O(N) time.

Space Complexity: O(N), since the code stores all the node values in a list.

*/