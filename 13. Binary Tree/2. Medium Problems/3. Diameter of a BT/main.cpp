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
    int diameter = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = maxDepth(root);
        return diameter;      
    }
};


/*

Time Complexity: O(N*N) where N is the number of nodes in the Binary Tree.

This arises as we calculate the diameter of each node and to calculate the height of its left and right children, we traverse the tree which is proportional to the number of nodes.
Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).
Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.


*/