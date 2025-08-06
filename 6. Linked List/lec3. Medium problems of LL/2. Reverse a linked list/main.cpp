// https://leetcode.com/problems/reverse-linked-list/description/

// https://takeuforward.org/data-structure/reverse-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;

        // reverse a singly linked list using stacks

        stack<int> st;

        while(temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }   
};

/*

Time Complexity: O(2N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and update the linked list. Both traversals take O(N) time, hence time complexity  O(2N) ~ O(N).

Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 

*/