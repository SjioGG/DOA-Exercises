#include "HashTable.h"
int main() {
    HashTable hashTable(11);

    hashTable.insert(22, "Value22");
    hashTable.insert(5, "Value5");
    hashTable.insert(16, "Value16");
    hashTable.insert(27, "Value27");
   // hashTable.insert(1, "Value1");
   // hashTable.insert(12, "Value12");
   // hashTable.insert(23, "Value23");
   // hashTable.insert(202208488, "studiernr");

    hashTable.printAllValues();
    std::cout << "Load Factor: " << hashTable.calculateLoadFactor() << std::endl;
    return 0;
}