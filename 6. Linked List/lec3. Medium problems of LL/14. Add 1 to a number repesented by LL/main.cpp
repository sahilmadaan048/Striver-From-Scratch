// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

class Solution {
  public:
    int solve(Node* temp){
        // go to the end 
        if(!temp->next){
            int carry = 0;
            temp->data += 1;
            if(temp->data == 10){
                temp->data = 0;
                carry = 1;
            }
    
            return carry; 
        }
    
        temp->data += solve(temp->next);
        int carry = 0;
        if(temp->data == 10){
            temp->data = 0;
            carry = 1;
        }
    
        return carry; 
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        
        int carry = solve(head);
        if(carry){
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
    
        return head;
    }
};