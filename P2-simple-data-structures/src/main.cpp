#include "../include/linked_list.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/hash_tabel.hpp"
#include <iostream>

int main() {
    // LinkedList Test
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.remove(20);
    list.display();

    // Stack Test
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();

    // Queue Test
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.display();

    // HashTable Test
    HashTable hashTable(5);
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);
    hashTable.insert(6, 300);
    hashTable.display();
    hashTable.remove(2);
    hashTable.display();
    std::cout << "Search key 6: " << hashTable.search(6) << std::endl;

    return 0;
}
