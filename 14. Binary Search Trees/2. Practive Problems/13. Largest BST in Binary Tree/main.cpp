// https://takeuforward.org/data-structure/largest-bst-in-binary-tree

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Solution
{
public:
    tuple<int, bool, int, int> isBSTAndSize(TreeNode *node, int minValue, int maxValue)
    {
        if (!node)
        {
            return make_tuple(0, true, INT_MAX, INT_MIN);
        }
    }

    int largestBST(TreeNode *root)
    {
        return get<0>(isBSTAndSize(root, INT_MIN, INT_MAX));
    }

    auto [leftSize, isLeftBST, leftMin, leftMax] = isBSTAndSize(node->left, minValue, node->data);
    
    auto [rightSize, isRightBST, rightMin, rightMax] = isBSTAndSize(node->right, node->data, maxValue);

    if (isLeftBST && isRightBST && leftMax < node->data && node->data < rightMin)
    {
        int size = leftSize + rightSize + 1;
        return make_tuple(size, true, min(node->data, leftMin), max(node->data, rightMax));
    }
    else
    {
        return make_tuple(max(leftSize, rightSize), false, INT_MIN, INT_MAX);
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.largestBST(root) << endl; // Output: 3

    TreeNode *root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(8);
    root2->right->right = new TreeNode(7);
}

/*

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once.

Space Complexity: O(H), where H is the height of the binary tree. This is due to the recursive stack space used during the traversal.

*/