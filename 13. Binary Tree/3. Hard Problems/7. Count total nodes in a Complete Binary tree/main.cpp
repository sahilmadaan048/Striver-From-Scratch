// https://leetcode.com/problems/count-complete-tree-nodes/

// https://takeuforward.org/binary-tree/count-number-of-nodes-in-a-binary-tree

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
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/*
    Time complexity: O(n) — because every node of the tree is visited once.
    Space complexity: O(h) — due to recursion stack, where h is the height of the tree.

*/