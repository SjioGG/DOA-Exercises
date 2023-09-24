#pragma once
#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    int size;
    std::vector<std::list<std::pair<int, std::string>>> table;
    int numElements; // Track #nr of elements added to hash map
public:
    HashTable(int tableSize) : size(tableSize), table(tableSize), numElements(0) {}

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
        numElements++;
    }

    std::string search(int key) {
        int index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return "Key not found";
    }

    void printAllValues() {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Index\tKey\tValue" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        for (int index = 0; index < size; ++index) {
            for (const auto& entry : table[index]) {
                std::cout << index << "\t" << entry.first << "\t" << entry.second << std::endl;
            }
        }
        std::cout << "---------------------------------------" << std::endl;
    }

    float calculateLoadFactor() {
        return static_cast<double>(numElements) / size; // Had to do this since the compiler optimizes it away when using float or double for some reason.
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const std::pair<int, std::string>& entry) {
            return entry.first == key;
            });
    }
};