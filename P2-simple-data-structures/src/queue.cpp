#include "../include/queue.hpp"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int data) {
    Node* newNode = new Node{data, nullptr};
    if (rear) {
        rear->next = newNode;
    }
    rear = newNode;
    if (!front) {
        front = rear;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    Node* temp = front;
    int dequeuedData = front->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    return dequeuedData;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::display() const {
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}
