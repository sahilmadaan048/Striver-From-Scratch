// https://takeuforward.org/data-structure/two-sum-in-bst-check-if-there-exists-a-pair-with-sum-k

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class Solution
{
public:
    void inorderTraversal(TreeNode *root, vector<int> &inorfder)
    {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int left = 0;
        int right = inorder.size() - 1;

        while (left < right)
        {
            int sum = inorder[left] + inorder[right];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return false;
    }
};

void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl;

    Solution solution;

    int target = 22;

    bool exists = solution.findTarget(root, target);

    if (exists)
        cout << "Pair with sum " << target << " exists." << endl;
    else
        cout << "Pair with sum " << target << " does not exist." << endl;

    return 0;
}

/*

Complexity Analysis

Time Complexity: O(N+N) where N is the number of nodes in the Binary Search Tree. To create the array that will store the inorder sequence, we have to traverse the entire BST, hence O(N) and to apply the two pointer approach and get the pair equal to sum again requires O(N) hence O(N+N) ~ O(2N) ~ O(N).

Space Complexity : O(N)where N is the number of nodes in the BST, as we have to store all the nodes in an additional data structure array. The two pointer approach does not use any additional space hence the space complexity is O(N).

*/