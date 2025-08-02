// https://www.youtube.com/watch?v=Nq7ok-OyEpg

// https://takeuforward.org/linked-list/linked-list-introduction

#include <bits/stdc++.h>
using namespace std;

class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int checkIsPresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point

    Node* head = convertArr2LL(arr);
    // traversal
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << lengthOfLL(head) << endl;

    cout << checkIsPresent(head, 5) << endl;
    return 0;
}

// never ever temper with head, if you do make sure original head is preserved 