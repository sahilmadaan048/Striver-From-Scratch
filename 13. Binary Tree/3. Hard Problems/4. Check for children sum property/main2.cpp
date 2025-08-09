// different solution for this problem

// if left + right >= root value,
// make root value = left + right
// else left = right = root value

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;

    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    void changeTree(TreeNode *root)
    {
        if (root == nullptr)
            return;

        int child = 0;
        if (root->left)
        {
            child += root->left->val;
        }
        if (root->right)
        {
            child += root->right->val;
        }

        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            if (root->left)
            {
                root->left->val = root->val;
            }
            if (root->right)
            {
                root->right->val = root->val;
            }
        }

        changeTree(root->left);
        changeTree(root->right);

        int total = 0;
        if (root->left)
        {
            total += root->left->val;
        }
        if (root->right)
        {
            total += root->right->val;
        }

        // if either left node or right node exists , update the value of the root node to the total sum
        if (root->left or root->right)
        {
            root->val = total;
        }
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            {
                return;
            }
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);

        return;
    }

};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    sol.inorderTraversal(root);
    cout << endl;
    
    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);
    
    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: ";
    sol.inorderTraversal(root);
    cout << endl;

    return 0;
}