// https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/

// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
    
        unordered_map<Node*, Node*> mpp;

        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL) {
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }
};


/*

Time Complexity: O(2N) where N is the number of nodes in the linked list. The linked list is traversed twice, once for creating copies of each node and for the second time to set the next and random pointers for each copied node. The time to access the nodes in the map is O(1) due to hashing.

Space Complexity : O(N)+O(N)where N is the number of nodes in the linked list as all nodes are stored in the map to maintain mappings and the copied linked lists takes O(N) space as well.

*/