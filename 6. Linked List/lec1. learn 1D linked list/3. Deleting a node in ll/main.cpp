// https://takeuforward.org/data-structure/delete-last-node-of-linked-list/

// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <Bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head = deleteTail(head);
    printLL(head);
}

/*

Time Complexity: O(N) for traversing the linked list and updating the tail.

Space Complexity: O(1), as we have not used any extra space.

*/