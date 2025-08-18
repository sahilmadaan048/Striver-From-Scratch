// https://takeuforward.org/data-structure/implement-queue-using-stack/

// https://leetcode.com/problems/implement-queue-using-stacks/description/


class MyQueue {
private:
    stack<int> input;
    stack<int> output;    

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};