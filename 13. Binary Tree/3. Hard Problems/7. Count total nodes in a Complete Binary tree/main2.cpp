// brute force approach 

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
    void inorder(TreeNode* root, int &count) {
        if (root == NULL) {
            return;
        }
        count++;
        inorder(root->left, count);
        inorder(root->right, count);
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int count = 0;
        inorder(root, count);
        return count;
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
    Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

Space Complexity : O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes. In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).

*/