#include "Set.h"

int main() {
    Set<int> Set;

    Set.insert(4);
    Set.insert(2);
    Set.insert(3);
    Set.insert(1);
    Set.insert(4); // Adding a duplicate element, which will be ignored

    
    cout << "Set elements: " << endl;
    Set.print();

    Set.remove(3);

    cout << "Set elements after removing 3: " << endl;
    Set.print();

    cout << "Is 4 in the set? " << (Set.contains(4) ? "Yes" : "No") << endl; // Should print "Yes"

    return 0;
}