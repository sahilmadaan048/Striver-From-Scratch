// https://takeuforward.org/data-structure/bst-iterator

// https://leetcode.com/problems/binary-search-tree-iterator/

// https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Solution
{
public:
    void inorderTraversal(Node *root, vector<int> &arr)
    {
        if (!root)
            return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->data);
        inorderTraversal(root->right, arr);
    }

    vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> merged;

        int i = 0, j = 0;

        while(i < arr1.size() and j < arr2.size()) {
            if(arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
            else merged.push_back(arr2[j++]);
        }

        while(i < arr1.size()) merged.push_back(arr1[i++]);
        while(j < arr3.size()) merged.push_back(arr2[j++]);

        return merged;
    }
 
    vector<int> mergeBSTs(Node *root1, Node *root2)
    {
        vector<int> arr1, arr2;
        inorderTraversal(root1, arr1);
        inorderTraversal(root2, arr2);
        return mergeArrays(arr1, arr2);
    }
};

int main()
{
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution sol;
    vector<int> result = sol.mergeBSTs(root1, root2);

    for (int val : result)
        cout << val << " ";
    return 0;
}

/*

complexity analysis 

time => o(n + m)
space => o(n + m)

*/