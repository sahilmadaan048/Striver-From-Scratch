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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        return (p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }
};

// https://leetcode.com/problems/same-tree/description/

/*

Time Complexity: O(N + M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree. This complexity arises from visiting each node of both trees during their comparison.

Space Complexity: O(1) as no additional space or data structures are created that are proportional to the input size of the tree.

*/