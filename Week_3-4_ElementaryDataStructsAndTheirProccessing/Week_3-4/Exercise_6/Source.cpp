#include "Set.h"

int main() {
    Set<int> Set;

    Set.insert(1);
    Set.insert(2);
    Set.insert(4);
    Set.insert(3);
    Set.insert(5); // Adding a duplicate element, which will be ignored

    
    cout << "Set elements: " << endl;
    Set.print(); // Should print 10 20 30

    Set.remove(3);

    cout << "Set elements after removing 20: " << endl;
    Set.print(); // Should print 10 30

    cout << "Is 30 in the set? " << (Set.contains(30) ? "Yes" : "No") << endl; // Should print "Yes"

    return 0;
}