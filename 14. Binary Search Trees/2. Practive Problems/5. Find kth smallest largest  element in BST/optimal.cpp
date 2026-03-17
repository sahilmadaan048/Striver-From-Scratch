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
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int countSmall = 0, kthSmall = -1;
    int countLarge = 0, kthLarge = -1;

    // Inorder → for kth smallest
    void inorder(TreeNode* root, int k) {
        if(!root || kthSmall != -1) return;

        inorder(root->left, k);

        countSmall++;
        if(countSmall == k) {
            kthSmall = root->val;
            return;
        }

        inorder(root->right, k);
    }

    // Reverse Inorder → for kth largest
    void reverseInorder(TreeNode* root, int k) {
        if(!root || kthLarge != -1) return;

        reverseInorder(root->right, k);

        countLarge++;
        if(countLarge == k) {
            kthLarge = root->val;
            return;
        }

        reverseInorder(root->left, k);
    }

public:
    // Function to get kth smallest
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kthSmall;
    }

    // Function to get kth largest
    int kthLargest(TreeNode* root, int k) {
        reverseInorder(root, k);
        return kthLarge;
    }
};


/*

Complexity Analysis
Time Complexity: O(N), where N is the number of nodes in the binary tree. The reason is that in the worst-case scenario, the inorder and reverse inorder traversals visit each node exactly once.

Space Complexity: O(H), where H is the height of the binary tree


*/