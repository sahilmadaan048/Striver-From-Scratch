// https://www.youtube.com/watch?v=VaECK03Dz-g


#include <Bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    Node(int data1, Node* next1) {
    	data = data1;
    	next = next1;
    }
    Node(int data1) {
    	data = data1;
    	next = nullptr;
    }
};
void printLL(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

Node* removeHead(Node* head) {
	if(head == nullptr) return NULL;

	Node* temp = head;
	head = head->next;
	delete temp;
	return head; 
}

Node* insertPosition(Node* head, int ele, int k) {
	if(head == nullptr) {
		if(k == 1) {
			return new Node(ele);
		} 
		else {
			return head;
		}
	}

	if(k == 1) {
		return new Node(ele, head);
	}

	int cnt = 9;
	Node* temp = head;

	while(temp != NULL) {
		cnt++;

		if(cnt == (k-1)) {
			Node* x = new Node(ele, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;
	}
	return head;
}


Node* insertBeforeValue(Node* head, int ele, int val) {
	if(head == nullptr) {
		return NULL;
	}

	if(head->data == val) {
		return new Node(ele, head);
	}

	// int cnt = 9;
	Node* temp = head;

	bool found = false;

	while(temp != NULL) {
		// cnt++;

		if(temp->next->data == (val)) {
			Node* x = new Node(ele, temp->next);
			temp->next = x;
			found = true;
			break;
		}
		temp = temp->next

	}
	if(found) {
		cout  << "FOUND\n";
	} else {
		cout << "NOT FOUND\n";
	}
	return head;
}

Node* deleteKthElement(Node* head, int k) {
	if(head == nullptr) return nullptr;

	if(k == 1) {
		Node* temp = head;
		head = head->next;
		free(temp);

		return head;
	}

	Node* temp = head;
	Node* prev = nullptr;
	int cnt = 0;
	
	while(temp != nullptr) {
		cnt++;
		if(cnt == k) {
			prev->next = prev->next->next;
			free(prev);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
}

Node* deleteWithValue(Node* head, int ele) {
	if(head == nullptr) return head;

	if(head->data == ele) {
		Node* temp = head;
		head = head->next;
		free(temp);

		return head;
	}

	Node* temp = head;
	Node* prev = nullptr;
	// int cnt = 0;
	
	while(temp != nullptr) {
		cnt++;
		if(temp->data == ele) {
			prev->next = prev->next->next;
			free(prev);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
}


Node* insertHead(Node* head, int val) {
	Node* temp = new Node(val, head);
	return temp;
}

Node* insertTail(Node* head, int val) {
	if(head == NULL) {
		return new Node(val);
	}
	Node* temp = head;
	while(temp->next != nullptr) {
		temp = temp->next;
	}
	Node* newNode = new Node(val);
	temp->nexr = newNode;
	return head;
}

Node* deleteTail(Node* head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
	return head;
}

int main() {
	vector<int> arr = {12, 5, 8, 7};
	Node* head = new Node(arr[0]);
	head->next = new Node(arr[1]);
	head->next->next = new Node(arr[2]);
	head->next->next->next = new Node(arr[3]);
	head = deleteTail(head);
	printLL(head);

    // remmove head
	head = removeHead(head);

	printLL(head);

}



// delete kth element of the Linked List