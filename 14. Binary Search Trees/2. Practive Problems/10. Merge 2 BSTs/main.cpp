// https://takeuforward.org/data-structure/bst-iterator

// https://leetcode.com/problems/binary-search-tree-iterator/

// https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {};
};

class Solution {
    public: 
    void traverse(Node* root, vector<int> &elements) {
        if(!root) return;
        traverse(root->left, elements);
        elements.push_back(root->data);
        traverse(root->right, elements);
    }

    vector<int> mergeBSTs(Node* root1, Node* root2) {
        vector<int> elements;
        traverse(root1, elements);
        traverse(root2, elements);
        sort(elements.begin(), elements.end());
        return elements;
    }
};

int main () {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(3);
    root2->left = new Node(0);
    root2->right = new Node(5);

    Solution sol;
    vector<int> result = sol.mergeBSTs(root1, root2);

    for (int val : result) {
        cout << val << " ";
    }
}

/*
complexity analysis

time => O((n+m)*log(n+m)), 
space => O(m + n) 

*/

