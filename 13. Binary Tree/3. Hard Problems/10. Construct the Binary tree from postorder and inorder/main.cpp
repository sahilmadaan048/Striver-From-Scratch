// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// https://takeuforward.org/data-structure/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd,
                    int &postIndex,
                    map<int,int>& mpp)
    {
        if(inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int inRoot = mpp[root->val];

        // build right first
        root->right = build(inorder, postorder, inRoot + 1, inEnd, postIndex, mpp);
        root->left  = build(inorder, postorder, inStart, inRoot - 1, postIndex, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;

        int n = inorder.size();

        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }   

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1, postIndex, mpp);
    }
};

/*

Complexity Analysis

Time Complexity: O(N), Every node is visited once.

Space Complexity: O(N), Due to hashmap and recursion stack (up to tree height).

*/