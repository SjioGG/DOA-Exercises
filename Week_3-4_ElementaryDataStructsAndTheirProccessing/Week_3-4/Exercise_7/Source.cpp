#include "Dictionary.h"
#include <iostream>
using namespace std;

int main()
{
    Dictionary<int, string> dict;

    dict.insert(4, "value1"); // calling the pair 
    dict.insert(7,"value2");
    dict.insert(10, "value3");
    

    cout << "The value of the key is:  " << dict["value1"] << endl; // Output: 4
    cout << "The value of the key is:  " << dict["value2"] << endl; // Output: 7
    cout << "The value of the key is:  " << dict["value3"] << endl; // Output: 10

    cout << "The size of the dictionary is " << dict.size() << endl; 

    cout << "Does the dictionary contain a key? " << dict.contains(4) << endl; 

    if (dict.empty()) // checks if the dictionary is empty
    {
        cout << "Dictionary is empty " << endl;
    }
    else
    {
        cout << "Dictionary is not empty " << endl;
    }
    
    return 0;
}