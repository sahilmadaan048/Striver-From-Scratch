// https://takeuforward.org/data-structure/inorder-successorpredecessor-in-bst

// http://geeksforgeeks.org/dsa/inorder-successor-in-binary-search-tree/

// https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

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
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        TreeNode *successor = nullptr;

        while (curr != nullptr)
        {

            if (curr->left == nullptr)
            {
                // visit node
                if (prev == p)
                {
                    successor = curr;
                }
                prev = curr;
                curr = curr->right;
            }
            else
            {
                // find inorder predecessor
                TreeNode *temp = curr->left;
                while (temp->right != nullptr && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (temp->right == nullptr)
                {
                    // make thread
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // remove thread
                    temp->right = nullptr;

                    // visit node
                    if (prev == p)
                    {
                        successor = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        return successor;
    }
};

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    TreeNode *p = root->left->right;

    Solution solution;
    TreeNode *successor = solution.inorderSuccessor(root, p);

    if (successor != nullptr)
    {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    }
    else
    {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    return 0;
}

/*

Complexity Analysis
Time Complexity: O(N) where N is the number of nodes in the binary search tree. This complexity arises from the fact that we have to traverse all nodes in an inorder fashion to get to the inorder successor.

Space Complexity: O(1) as no additional data structure or memory allocation is done during the traversal and algorithm. Only a value comparison at each node.

*/