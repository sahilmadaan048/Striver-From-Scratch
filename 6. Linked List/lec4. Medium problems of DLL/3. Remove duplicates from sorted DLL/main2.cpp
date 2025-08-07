// https://takeuforward.org/plus/dsa/problems/remove-duplicated-from-sorted-dll?tab=editorial

// https://www.youtube.com/watch?v=YJKVTnOJXSY


class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            ListNode* nextNode = temp->next;

            // Remove all duplicates of current value
            while (nextNode != nullptr && nextNode->val == temp->val) {
                ListNode* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate; 
            }

            // Link temp to the next unique node
            temp->next = nextNode;
            if (nextNode != nullptr) {
                nextNode->prev = temp;
            }

            temp = temp->next;
        }
        return head;
    }
};
