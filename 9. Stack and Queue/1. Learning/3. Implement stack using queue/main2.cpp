
// https://www.youtube.com/watch?v=3Et9MrMc02A

// https://takeuforward.org/data-structure/implement-stack-using-single-queue/

// https://leetcode.com/problems/implement-stack-using-queues/description/?source=submission-ac


#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void Push(int x) {
        // push into q2
        q2.push(x);
        // move everything from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // swap queues
        swap(q1, q2);
    }

    int Pop() {
        if(q1.empty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        int n = q1.front();
        q1.pop();
        return n;
    }

    int Top() {
        if(q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    int Size() {
        return q1.size();
    }
};

int main() {
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size() << endl;

    return 0;
}
