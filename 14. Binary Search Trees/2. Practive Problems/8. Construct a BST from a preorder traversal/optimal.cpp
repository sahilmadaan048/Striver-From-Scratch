// https://takeuforward.org/data-structure/construct-a-bst-from-preorder-traversal

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


class Solution {
    int i = 0;

    TreeNode* build(vector<int>& preorder, int bound) {
        if(i == preorder.size() || preorder[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};



/*

Complexity Analysis

Time Complexity: O(N), Each node is processed once while constructing the BST.

Space Complexity: O(H), Stack space for recursion, where H is the height of the tree.

*/