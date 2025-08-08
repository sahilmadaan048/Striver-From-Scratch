// https://takeuforward.org/linked-list/search-an-element-in-a-linked-list
// https://www.youtube.com/watch?v=Nq7ok-OyEpg

#include <bits/stdc++.h>
using namespace std; 

class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node in the      list

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == desiredElement)
            return 1;

        temp = temp->next;
    }

    return 0;  
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 2;
    cout << checkifPresent(head, val) << '\n';

    return 0;
}