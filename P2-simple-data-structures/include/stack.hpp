#ifndef STACK_HPP
#define STACK_HPP

class Stack {
public:
    Stack();
    ~Stack();

    void push(int data);
    int pop();
    bool isEmpty() const;
    void display() const;

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;
};

#endif // STACK_HPP
