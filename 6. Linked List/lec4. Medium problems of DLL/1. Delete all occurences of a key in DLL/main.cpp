// https://www.youtube.com/watch?v=Mh0NH_SD92k

// https://takeuforward.org/plus/dsa/problems/delete-all-occurrences-of-a-key-in-dll?tab=editorial

// dlete all occurences of a  kay in DLL

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;
        
        while(temp != null) {
            if(temp->val == target) {
                // if this is the head of the ll 
                // then post dell;etion the head will be updated
                if(temp == head) {
                    head = temp->next;
                }
                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                if(nextNode != nullptr) nextNode->prev = prevNode;
                if(prevNode != nullptr) prevNode->next = nextNode;

                free(temp);

                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};