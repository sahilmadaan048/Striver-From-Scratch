// https://takeuforward.org/plus/dsa/problems/sort-a-ll-of-0's-1's-and-2's

class Solution {
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoSortedLinkedLists(ListNode* ls1, ListNode* ls2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (ls1 != nullptr && ls2 != nullptr) {
            if (ls1->val <= ls2->val) {
                temp->next = ls1;
                ls1 = ls1->next;
            } else {
                temp->next = ls2;
                ls2 = ls2->next;
            }
            temp = temp->next;
        }

        if (ls1 != nullptr) {
            temp->next = ls1;
        } else {
            temp->next = ls2;
        }

        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;

        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);
    }
};


