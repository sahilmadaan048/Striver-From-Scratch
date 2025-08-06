// https://takeuforward.org/linked-list/length-of-loop-in-linked-list


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to return the length 
// of loop using hashing

int lengthOfLoop(Node* head) {
    // Hashmap to store visited
    // nodes and their timer values
    unordered_map<Node*, int> visitedNodes; 
    
    // Initialize pointer to
    // traverse the linked list
    Node* temp = head; 
    
    // Initialize timer to track
    // visited nodes
    int timer = 0; 

    // Traverse the linked list till
    // temp reaches nullptr
    while (temp != NULL) {
        
        // If revisiting a node return
        // the difference of timer values
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            // Calculate the length of the loop
            int loopLength = timer - visitedNodes[temp];
            
            // Return the length of the loop
            return loopLength; 
        }
        // Store the current node and
        // its timer value in the hashmap
        visitedNodes[temp] = timer;
        
        // Move to the next node
        temp = temp->next;
        
         // Increment the timer
        timer++;
    }

    // If traversal is completed and
    // we reach the end of the list (null)
    // means there is no loop
    return 0;
}



int main() {
    // Create a sample linked
    // list with a loop
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}

/*

Time Complexity: O(N) The code traverses the entire linked list at least once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).

Space Complexity: O(N) The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional space, where ‘N' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.
*/