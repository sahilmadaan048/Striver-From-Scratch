// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1947763523/

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                pre->right = curr->right;

                curr->right = curr->left;

                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};


/*

Complexity Analysis
Time Complexity: O(2N) where N is the number of nodes in the Binary Tree. The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it). In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.

Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size. Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm. The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.

*/