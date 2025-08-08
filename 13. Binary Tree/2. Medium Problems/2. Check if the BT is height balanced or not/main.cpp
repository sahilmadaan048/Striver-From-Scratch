// https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/


// https://leetcode.com/problems/balanced-binary-tree/description/



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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);

        if (leftHeight == -1) 
            return -1;

        int rightHeight = dfsHeight(root->right);

        if (rightHeight == -1) 
            return -1;

        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // if (root == nullptr) return true;

        // int leftHeight = maxDepth(root->left);
        // int rightHeight = maxDepth(root->right);

        // if (abs(leftHeight - rightHeight) <= 1 &&
        //     isBalanced(root->left) &&
        //     isBalanced(root->right)) {
        //     return true;
        // }

 
        // return false;
 
        return dfsHeight(root) != -1;
    }
};



/*

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.


*/