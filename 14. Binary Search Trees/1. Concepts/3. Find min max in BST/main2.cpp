#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (root == nullptr) {
        cout << "BST is empty\n";
        return -1; // or handle appropriately
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->val;
}
