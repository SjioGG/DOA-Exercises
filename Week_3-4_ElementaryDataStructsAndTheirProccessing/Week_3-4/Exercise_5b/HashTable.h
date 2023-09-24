#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class HashTable {
private:
    int size;
    int numElements;
    std::vector<std::pair<int, std::string>> table;

    int getNextPrime(int n) {
        while (true) {
            n++;
            if (isPrime(n)) {
                return n;
            }
        }
    }

    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    void resize(int newSize) {
        std::vector<std::pair<int, std::string>> newTable(newSize, std::make_pair(-1, ""));

        // Rehash existing elements into the new table.
        for (const auto& entry : table) {
            if (entry.first != -1) {
                int index = entry.first % newSize;
                while (newTable[index].first != -1) {
                    index = (index + 1) % newSize; // Linear probing.
                }
                newTable[index] = entry;
            }
        }

        size = newSize;
        table = newTable;
    }

public:
    HashTable(int initialSize) : size(initialSize), numElements(0), table(initialSize, std::make_pair(-1, "")) {}

    void insert(int key, const std::string& value) {
        if (static_cast<double>(numElements) / size > 0.7) { // Check the load factor.
            int newSize = getNextPrime(size * 2); // Double the size and find the next prime.
            resize(newSize);
        }

        int index = key % size;

        while (table[index].first != -1) {
            // Linear probing: Move to the next slot until an empty slot is found.
            index = (index + 1) % size;
        }

        table[index] = std::make_pair(key, value);
        numElements++;
    }

    std::string search(int key) {
        int index = key % size;

        while (table[index].first != -1) {
            if (table[index].first == key) {
                return table[index].second;
            }

            // Linear probing: Move to the next slot.
            index = (index + 1) % size;
        }

        return "Key not found";
    }

    void printAllValues() {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Index\tKey\tValue" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        for (int index = 0; index < size; ++index) {
            if (table[index].first != -1) {
                std::cout << index << "\t" << table[index].first << "\t" << table[index].second << std::endl;
            }
        }
        std::cout << "---------------------------------------" << std::endl;
    }

    float calculateLoadFactor() {
        return static_cast<float>(numElements) / size; // Use float for the result since the return type is float.
    }
};
