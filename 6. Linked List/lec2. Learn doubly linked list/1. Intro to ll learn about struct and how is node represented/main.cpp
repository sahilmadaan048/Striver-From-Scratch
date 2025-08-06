// https://www.youtube.com/watch?v=0eKMU10uEDI

// https://takeuforward.org/linked-list/introduction-to-doubly-linked-list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertToDll(vector<int> &temp)
{
    int n = temp.size();
    Node *head = new Node(temp[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(temp[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode; // or prev = temp
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return NULL;
    }

    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = nullptr;

    tail->back = nullptr;
    delete tail;
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == nullptr)
    {
        return NULL;
    }

    int cnt = 0;
    Node *kNode = head;

    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }

    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL and front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;

    delete kNode;
    return head;
}

void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

Node *insertBeforeHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head == nullptr || head->next == nullptr)
    {
        // Only one node or empty list — insert at beginning
        Node *newNode = new Node(val, head, nullptr);
        if (head)
            head->back = newNode;
        return newNode;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

Node *insertBeforeKthElement(Node *head, int k, int val)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main()
{
    vector<int> temp = {1, 3, 2, 4, 5, 6, 7, 8, 9};

    Node *head = convertToDll(temp);
    printDLL(head);
    cout << endl;

    head = deleteHead(head);
    printDLL(head);
    cout << endl;

    head = deleteTail(head);
    printDLL(head);
    cout << endl;

    head = removeKthElement(head, 5);
    printDLL(head);
    cout << endl;

    deleteNode(head->next);
    printDLL(head);
    cout << endl;

    deleteNode(head->next->next);
    printDLL(head);
    cout << endl;

    head = insertBeforeHead(head, 10);
    printDLL(head);
    cout << endl;

    head = insertBeforeTail(head, 10);
    printDLL(head);
    cout << endl;

    head = insertBeforeKthElement(head, 1, 10);
    printDLL(head);
    cout << endl;

    insertBeforeNode(head->next->next, 20);
    printDLL(head);
    cout << endl;
}