// https://takeuforward.org/data-structure/construct-a-bst-from-preorder-traversal

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i<preorder.size(); i++) {
            TreeNode* curr = root;

            while(true) {
                if(preorder[i] < curr->val) {
                    if(curr->left == nullptr) {
                        curr->left = new TreeNode(preorder[i]);
                        break;
                    }
                    else curr = curr->left;
                }
                else {
                    if(curr->right == nullptr) {
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else curr = curr->right;
                }
            }
        }

        return root;
    }
};

/*

Complexity Analysis

Time Complexity: O(N2) as We traverse the entire array of N elements and for each element insertion, we make comparisons and insert it into the tree starting from the root resulting in a time complexity of O(N x N) = O(N2).

Space Complexity: O(N), as we create a binary search tree proportional to the number of nodes in the preorder array.

*/