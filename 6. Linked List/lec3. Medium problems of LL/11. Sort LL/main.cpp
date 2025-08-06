// https://takeuforward.org/linked-list/sort-a-linked-list

// https://leetcode.com/problems/sort-list/description/

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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;

        int ind = 0;
        while(temp != nullptr) {
            temp->val = arr[ind];
            ind++;
            temp = temp->next;
        }

        return head;
    }

};


/*

Time Complexity: O(N) + O(N log N) + O(N)where N is the number of nodes in the linked list.

O(N) to traverse the linked list and store its data values in an additional array.
O(N log N) to sort the array containing the node values.
O(N) to traverse the sorted array and convert it into a new linked list.
Space Complexity : O(N)where N is the number of nodes in the linked list as we have to store the values of all nodes in the linked list in an additional array to sort them.

*/