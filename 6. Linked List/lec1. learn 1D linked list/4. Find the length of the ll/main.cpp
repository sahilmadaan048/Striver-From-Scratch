// https://takeuforward.org/linked-list/find-the-length-of-a-linked-list

// https://takeuforward.org/plus/dsa/problems/find-the-length-of-the-linked-list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int lengthOfLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;

    while (temp != NULL) {
        temp = temp->next;
        cnt++; // increment cnt for every node traversed
    }
    return cnt;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    
    Node* head = new Node(arr[0]);

    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    
    cout << lengthOfLinkedList(head) << '\n';
}