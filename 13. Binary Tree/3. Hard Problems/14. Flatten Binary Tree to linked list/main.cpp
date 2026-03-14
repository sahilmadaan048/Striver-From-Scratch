// https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


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
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
       if(!root) return;

       flatten(root->right);

       flatten(root->left);

       root->right = prev;
       root->left = nullptr;

       prev = root; 
    }
};


/*

Complexity Analysis
Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited once during the flattening process.

Space Complexity: O(log2N), where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).     

*/