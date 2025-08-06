// https://leetcode.com/problems/palindrome-linked-list/description/

// https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/

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
    bool isPalindrome(ListNode* head) {
        stack<int> st;

        ListNode* temp = head;

        while(temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }   

        temp = head;

        while(temp != nullptr) {
            if(temp->val != (st.top())) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};

/*

Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.

Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 

*/