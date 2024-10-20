#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>
#include <list>

class HashTable {
public:
    HashTable(int size);
    void insert(int key, int value);
    bool remove(int key);
    int search(int key);
    void display() const;

private:
    int hashFunction(int key) const;
    std::vector<std::list<std::pair<int, int>>> table;
    int size;
};

#endif // HASHTABLE_HPP
