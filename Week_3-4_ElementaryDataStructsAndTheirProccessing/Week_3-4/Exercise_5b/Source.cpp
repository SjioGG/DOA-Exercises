#include "HashTable.h"
int main() {
    HashTable hashTable(7);

    hashTable.insert(5, "Value5");
    hashTable.insert(28, "Value28");
    hashTable.insert(19, "Value19");
    hashTable.insert(15, "Value15");
    hashTable.insert(20, "Value20");
    hashTable.insert(33, "Value33");
    hashTable.insert(12, "Value12");
    hashTable.insert(17, "Value17");
    hashTable.insert(33, "Value33_again");
    hashTable.insert(10, "Value10");

    hashTable.printAllValues();
    std::cout << "Load Factor: " << hashTable.calculateLoadFactor() << std::endl;
    return 0;
}