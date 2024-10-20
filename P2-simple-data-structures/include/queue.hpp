#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int data);
    int dequeue();
    bool isEmpty() const;
    void display() const;

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
};

#endif // QUEUE_HPP
