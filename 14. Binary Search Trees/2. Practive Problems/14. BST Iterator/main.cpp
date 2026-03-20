// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        TreeNode *node = root;

        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();

        TreeNode *nodeRight = node->right;
        while (nodeRight)
        {
            st.push(nodeRight);
            nodeRight = nodeRight->left;
        }
        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*

Time Complexity:

next() → Amortized O(1)
hasNext() → O(1)
Each node is pushed and popped once
Space Complexity:

O(h) (height of tree)
Worst case: O(n) (skewed tree)

*/