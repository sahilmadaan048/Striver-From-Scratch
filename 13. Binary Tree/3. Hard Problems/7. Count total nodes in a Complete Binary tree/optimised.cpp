#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        // If heights are equal, it's a perfect binary tree
        // that means the last level is filled completely
        // which is it is a perfect binary tree
        // thus use direct forumla
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    int totalNodes = sol.countNodes(root);

    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;

    return 0;
}

/*

Complexity Analysis

Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree. The calculation of leftHeight and rightHeight takes O(log N) time.In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree) Therefore, the total time complexity is O(log N * log N).

Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree. The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.Since the given tree is a complete binary tree, the height will always be log N.Therefore, the space complexity is O(log N).

*/