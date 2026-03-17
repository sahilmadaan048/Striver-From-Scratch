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

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};

};

class Solution
{
    public:
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int idx = binarySearch(inorder, p->val);
    
        if(idx == (int)inorder.size() - 1 || idx == -1) {
            return nullptr;
        }
        return new TreeNode(inorder[idx+1]);
    }
    
    int binarySearch(vector<int>& arr, int target) {
        int lo = 0, hi = (int)arr.size() - 1;

        while(lo <= hi) {   
            int mid = lo +  (hi - lo) / 2;

            if(arr[mid] == target) return mid;

            else if(arr[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return -1;
    }

};

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
Time Complexity: O(N + logN) where N is the number of nodes of the binary search tree. O(N) to traverse all nodes and store them in an inorder array and O(log N) for the binary search.

Space Complexity: O(N) as an array of size N is used to store the inorder traversal of the binary search tree.


*/