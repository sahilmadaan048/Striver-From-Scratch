// https://takeuforward.org/plus/dsa/problems/remove-duplicated-from-sorted-dll?tab=editorial

// https://www.youtube.com/watch?v=YJKVTnOJXSY

class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* curr = head;

        while (curr !=nullptr && curr->next!=nullptr) {
            if (curr->val == curr->next->val) {
                // Duplicate found, remove next node
                ListNode* temp = curr->next;
                curr->next = temp->next;
                if (temp->next) {
                    temp->next->prev = curr;
                }
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
