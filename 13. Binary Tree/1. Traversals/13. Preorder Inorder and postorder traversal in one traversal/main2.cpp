#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> preInPostTraversal(Node* root) {
    if(!root) {
        return {};
    }

    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});


    while(!st.empty()) {
        auto &it  = st.top();
        
        if(it.second == 1) {
            pre.push_back(it.first->data);

            it.second = 2;
            
            if(it.first -> left != nullptr) {
                st.push({it.first->left, 1});
            }
        }   
        else if(it.second == 2) {
            in.push_back(it.first->data);

            it.second = 3;

            if(it.first->right != nullptr) {
                st.push({it.first->right, 2});
            }
        }
        else {
            post.push_back(it.first->data);
            st.pop();
        }
    }
    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);


    return ans;
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

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
                            