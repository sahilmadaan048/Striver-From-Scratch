// https://takeuforward.org/data-structure/two-sum-in-bst-check-if-there-exists-a-pair-with-sum-k

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data): val(data), left(nullptr), right(nullptr) {};
};


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

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse) {
                node = node->right;   // for reverse inorder
            } else {
                node = node->left;    // for normal inorder
            }
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (reverse) {
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // inorder (smallest first)
        BSTIterator r(root, true);  // reverse inorder (largest first)

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } 
            else if (i + j < k) {
                if (l.hasNext())
                    i = l.next();
                else
                    break;
            } 
            else {
                if (r.hasNext())
                    j = r.next();
                else
                    break;
            }
        }
        return false;
    }
};

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main() {
    TreeNode* root = new TreeNode(7);
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

    if (exists) cout << "Pair with sum " << target << " exists." << endl;
    else cout << "Pair with sum " << target << " does not exist." << endl;

    return 0;
}

/*
complexity analysis 

time => o(N) where n isthe number of nodes int he bST Aas wr have to traverse all the nodes using the i and j pointers to find the pair with the sum = k

space => o(H) where H is the height of the BST as the BSTIterator class uses a stack to store the nodes
At maximum the size of suxh a stack will be equal to the height of the binary tree 

*/