// https://leetcode.com/problems/binary-tree-inorder-traversal/

// https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/

#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


/*

Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).

*/