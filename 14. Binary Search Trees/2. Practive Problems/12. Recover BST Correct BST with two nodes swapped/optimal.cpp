// https://takeuforward.org/data-structure/recover-bst-correct-bst-with-two-nodes-swapped

// https://leetcode.com/problems/recover-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev && root->val < prev->val)
        {
            if (!first)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }

    void printInorder(TreeNode *root)
    {
        if (!root)
            return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);

    Solution sol;

    cout << "Before fixing: ";
    sol.printInorder(root);
    cout << endl;

    sol.recoverTree(root);

    cout << "After fixing: ";
    sol.printInorder(root);
    cout << endl;

    return 0;
}

/*

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the Binary Search Tree as the algorithm involves performing an inorder traversal to
identify the swapped nodes.

Space Complexity: O(N), extra recursion space for getting the inorder traversal.


*/