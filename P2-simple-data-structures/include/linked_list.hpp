#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    void insert(int data);
    void remove(int data);
    void display() const;

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
};

#endif // LINKEDLIST_HPP
