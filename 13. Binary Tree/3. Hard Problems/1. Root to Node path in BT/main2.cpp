// https://www.geeksforgeeks.org/dsa/print-path-root-given-node-binary-tree/


// https://takeuforward.org/data-structure/print-root-to-node-path-in-a-binary-tree/


// Another Approach(Iterative Approach Using Stack):



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void printPath(Node* root, int target) {
    vector<int> path;
    stack<Node*> nodeStack;

    Node* curr = root;
    Node* prev = NULL;


    while(curr || !nodeStack.empty()) {
        while(curr) {
            nodeStack.push(curr);
            path.push_back(curr->data);
            curr = curr->left;
        }

        curr = nodeStack.top();

        
        if(curr->right and curr->right != prev) {
            curr = curr->right;
        }
        else {
            if(curr->data == target) {
                for(int i=0; i<path.size(); i++) {
                    cout << path[i] << "->";
                }
                cout << path[path.size()-1] << endl;
                return;
            }
            nodeStack.pop();
            path.pop_back();
            prev = curr;
            curr = NULL;
        }
    }
    cout << "No Path" << endl;

}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    printPath(root, target);
    return 0;
}