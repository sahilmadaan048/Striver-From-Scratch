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

class Solution {
    void insertCopyinLL(Node* head) {
        Node* temp = head;

        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            temp->next = copy;
            copy->next = nextElement;

            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;

            if (temp->random) {
                copyNode->random = temp->random->next;  //  key part
            }

            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* copyTail = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;
            copyTail->next = copyNode;
            copyTail = copyNode;

            temp->next = copyNode->next;  // Restore original list
            temp = temp->next;
        }

        return dummyNode->next;
    }

public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        insertCopyinLL(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};



/*

Time Complexity: O(3N)where N is the number of nodes in the linked list. The algorithm makes three traversals of the linked list, once to create copies and insert them between original nodes, then to set the random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.

Space Complexity : O(N) where N is the number of nodes in the linked list as the only extra additional space allocated it to create the copied list without creating any other additional data structures.

*/