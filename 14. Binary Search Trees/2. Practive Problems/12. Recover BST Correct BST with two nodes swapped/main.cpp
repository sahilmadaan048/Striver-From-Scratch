// https://takeuforward.org/data-structure/recover-bst-correct-bst-with-two-nodes-swapped

// https://leetcode.com/problems/recover-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    void inorder(TreeNode *root, vector<int> &values)
    {
        if (root == nullptr)
            return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> sortedVals;

        inorder(root, sortedVals);

        sort(sortedVals.begin(), sortedVals.end());

        TreeNode* current = root;
        int index = 0;

        // morris traversal to travberse the
        // BST without recusrion or stack
        while(current != nullptr) {
            if(current->left == nullptr) {
                if(current->val != sortedVals[index]) {
                    current->val = sortedVals[index];
                }
                ++index;
                // move to the right subtree
                current = current->right;
            }
            else {
                TreeNode* predecessor= current->left;

                while(predecessor->right != nullptr and predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    predecessor->right = nullptr;

                    if(current->val != sortedVals[index]){
                        current->val = sortedVals[index];
                    }
                    ++index;
                    current = current->right;
                }
            }
        }
    }
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void swapNodes(TreeNode *a, TreeNode *b)
{
    // Swap values of the nodes
    int temp = a->val;
    a->val = b->val;
    b->val = temp;

    // Swap left subtrees of the nodes
    TreeNode *tempLeft = a->left;
    a->left = b->left;
    b->left = tempLeft;

    // Swap right subtrees of the nodes
    TreeNode *tempRight = a->right;
    a->right = b->right;
    b->right = tempRight;
}

int main()
{
    Solution solution;

    TreeNode *root = nullptr;
    root = insert(root, 3);
    insert(root, 1);
    insert(root, 4);
    insert(root, 2);

    cout << "Original BST: ";
    inorderTraversal(root);
    cout << endl;

    TreeNode *node4 = root->right;
    TreeNode *node2 = root->left->right;
    swapNodes(node4, node2);

    cout << "BST with swapped nodes: ";
    inorderTraversal(root);
    cout << endl;

    solution.recoverTree(root);

    cout << "Recovered BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

/*

Complexity Analysis

Time Complexity: O(2*N + N*logN), We traverse the entire tree twice. In addition, we also sort the array to get correct inorder traversal

Space Complexity: O(N), for storing the traversal in a data structure and extra recursion space for getting the inorder traversal.

*/