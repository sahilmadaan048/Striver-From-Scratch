// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// https://takeuforward.org/binary-search-tree/lca-in-binary-search-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr) {
            return right;
        } else if(right == nullptr) {
            return left;
        }
        else return root;   
    }
};

/*

Complexity Analysis
Time Complexity: O(h), where h is height of tree. In case of a skewed tree height can be equal to number of nodes.
Space Complexity: O(1), no extra space is used.


*/