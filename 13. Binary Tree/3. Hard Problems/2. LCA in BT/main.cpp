// https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/

// https://www.youtube.com/watch?v=_-QHfMDde90&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F


// https://www.youtube.com/watch?v=_-QHfMDde90&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F




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
        if(root == nullptr or root == p or root == q) {
            return root;
        }   

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL) {
            return right;
        }
       else  if(right == NULL) {
            return left;
        }
        else return root;
    }
};  


/*
Time complexity: O(N) where n is the number of nodes.

Space complexity: O(N), auxiliary space.


*/