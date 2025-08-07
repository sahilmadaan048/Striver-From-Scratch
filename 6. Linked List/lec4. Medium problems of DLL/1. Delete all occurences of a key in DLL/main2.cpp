// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp != nullptr) {
            if (temp->data == x) {
                Node* nextNode = temp->next;

                // If it's the head node
                if (temp == *head_ref) {
                    *head_ref = nextNode;
                    if (nextNode) nextNode->prev = nullptr;
                    delete temp;
                } else {
                    Node* prevNode = temp->prev;
                    if (prevNode) prevNode->next = nextNode;
                    if (nextNode) nextNode->prev = prevNode;
                    delete temp;
                }

                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
    }
};
