class Solution {
    int height(TreeNode* node, int& diameter) {
        if(!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
    
        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }   

    public: 
    int diameter(TreeNode* root) {
        int diameter = 0;
        int h = height(root, diameter);
        return diameter;
    }
};

// https://leetcode.com/problems/diameter-of-binary-tree/



/*

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree.

*/