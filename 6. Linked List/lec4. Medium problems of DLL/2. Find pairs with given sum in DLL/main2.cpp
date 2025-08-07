// https://www.youtube.com/watch?v=YitR4dQsddE`
// https://takeuforward.org/plus/dsa/problems/find-pairs-with-given-sum-in-doubly-linked-list?tab=editorial

// find all paris with given sum in a ll

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/


class Solution
{
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        vector<vector<int>> ans;
        if (!head || !head->next) return ans;

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            while (nextNode != nullptr) {
                if (curr->val + nextNode->val == target) {
                    ans.push_back({curr->val, nextNode->val});
                }
                nextNode = nextNode->next;
            }
            curr = curr->next;
        }

        return ans;
    }
};


/*

O(n^2)

the interviewer will not be happy so optimise it to O(n)


can use binary serahc also at some stage since the Linked list is doubly and sorted
*/