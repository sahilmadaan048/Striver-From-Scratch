// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

// https://takeuforward.org/binary-search-tree/insert-a-given-node-in-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        TreeNode* dummy = root;

        while(true) {
            if(val < (root->val)) {
                if(root->left == NULL) {
                    root->left = new TreeNode(val); 
                    break;
                } else {
                    root = root->left;
                }
            }
            else {
                if(root->right == NULL) {
                    root->right = new TreeNode(val);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};


/*

Complexity Analysis
Time Complexity: O(H), where H is the height of the BST. In the worst case (unbalanced tree), it could be O(n).
Space Complexity: O(H), additional space used for recursion stack.

*/