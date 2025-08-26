// C++ program to merge K sorted linked lists
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to get node with minimum value
Node* getMinNode(vector<Node*> &arr) {
    
    Node* mini = nullptr;
    int index = -1;
    
    for (int i=0; i<arr.size(); i++) {
        
        // If current list is processed
        if (arr[i]==nullptr) continue;
        
        // If min node is not set or 
        // current head has smaller value.
        if (mini==nullptr || arr[i]->data<mini->data) {
            index = i;
            mini = arr[i];
        }
    }
    
    // Increment the head node 
    if (index!=-1) arr[index] = arr[index]->next;
    
    return mini;
}

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& arr) {
  
    // Create a dummy node to simplify 
    // the merging process
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    
    Node* mini = getMinNode(arr);
    
    // Process all nodes.
    while (mini != nullptr) {
        
        // Append min node to the result.
        tail->next = mini;
        tail = mini;
        
        // Find the next min node 
        mini = getMinNode(arr);
    }

    // Return the merged list starting
    // from the next of dummy node
    return dummy->next;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}