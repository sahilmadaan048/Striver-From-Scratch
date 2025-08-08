// https://leetcode.com/problems/symmetric-tree/description/

// https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/


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


 /*
 
    
 */
class Solution {
    bool solve(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr || r2 == nullptr) {
            return r1 == r2; // true only if both are null
        }

        return (r1->val == r2->val) && 
               solve(r1->left, r2->right) &&
               solve(r1->right, r2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return solve(root->left, root->right);
    }
};


/*
ime Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal and the function compares the nodes in a symmetric manner.

Space Complexity: O(1) as no additional data structures or memory is allocated.

O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.


*/