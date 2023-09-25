#include "Dictionary.h"
#include <iostream>
using namespace std;

int main()
{
    Dictionary<string, int> dict;

    dict.insert("value1", 4); // calling the pair 
    dict.insert("value2", 7);
    dict.insert("value3", 10);
    dict.insert("value4", 0);

    cout << "The value of the key is" << dict["value1"] << endl; // Output: 4
    cout << "The value of the key is" << dict["value2"] << endl; // Output: 7
    cout << "The value of the key is" << dict["value3"] << endl; // Output: 10

    if dict.Empty();
    {
        cout << "Dictionary is empty\n";
    }


    return 0;
}