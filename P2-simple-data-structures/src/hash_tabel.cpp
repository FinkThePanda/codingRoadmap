#include "../include/hash_tabel.hpp"
#include <iostream>

HashTable::HashTable(int size) : size(size), table(size) {}

int HashTable::hashFunction(int key) const {
    return key % size;
}

void HashTable::insert(int key, int value) {
    int index = hashFunction(key);
    table[index].push_back({key, value});
}

bool HashTable::remove(int key) {
    int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            return true;
        }
    }
    return false;
}

int HashTable::search(int key) {
    int index = hashFunction(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return -1;
}

void HashTable::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }
}
