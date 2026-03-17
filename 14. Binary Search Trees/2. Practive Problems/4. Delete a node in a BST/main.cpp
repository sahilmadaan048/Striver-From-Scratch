// https://leetcode.com/problems/delete-node-in-a-bst/description/

// https://takeuforward.org/binary-search-tree/delete-a-node-in-binary-search-tree


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
    TreeNode* findMin(TreeNode* root) {
        if(!root) return nullptr;
        while(root->left) {
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        if(root == nullptr) {
            return nullptr;
        }

        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if(root->left == nullptr) {
                return root->right;
            }
            else if(root->right == nullptr) {

                return root->left;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);            
        }
        return root;
    }
};


/*

Complexity Analysis
Time Complexity: O(H), Where H is the height of the tree; in the worst case (unbalanced BST), it could be O(n).
Space Complexity: O(H), Due to the recursion stack used in deleting and rebalancing the tree; also O(n) in the worst case.

*/