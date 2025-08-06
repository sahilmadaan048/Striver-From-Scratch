class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: only one node
        if (head == nullptr || head->next == nullptr) return nullptr;

        int cnt = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt / 2;

        temp = head;

        if (mid == 0) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        while (--mid > 0) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};
