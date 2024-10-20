#include "../include/stack.hpp"
#include <iostream>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }
    Node* temp = top;
    int poppedData = top->data;
    top = top->next;
    delete temp;
    return poppedData;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::display() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}
