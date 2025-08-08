    // https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/

    // https://leetcode.com/problems/diameter-of-binary-tree/description/



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
    // int diameter = 0;
    // int maxDepth(TreeNode* root) {
    //     if(root == nullptr) return 0;

    //     int lh = maxDepth(root->left);
    //     int rh = maxDepth(root->right);

    //     diameter = max(diameter, lh + rh);
    //     return 1 + max(lh, rh);
    // }
    
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int h = height(root, diameter);
        return diameter;      
    }
};

/*

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N

*/