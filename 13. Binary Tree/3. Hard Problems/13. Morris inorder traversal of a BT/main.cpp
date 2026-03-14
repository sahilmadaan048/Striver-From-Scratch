// https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree


// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// https://www.youtube.com/watch?v=PUfADhkq1LI

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        TreeNode *curr = root;

        while (curr != nullptr)
        {
            if (curr->left == nullptr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // create the inorder predecessor
                TreeNode *IP = curr->left;
                while (IP->right != NULL and IP->right != curr)
                {
                    IP = IP->right;
                }

                if (IP->right == nullptr)
                {
                    IP->right = curr;
                    curr = curr->left;
                }
                else
                {
                    IP->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

/*
    Time Complexity: O(2N), the time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
Space Complexity: O(1), the space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

*/