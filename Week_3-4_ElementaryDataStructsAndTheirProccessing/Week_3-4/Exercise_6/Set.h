#pragma once
#include <iostream>
#include "double_list.h"
using namespace std;

template <typename Object>
class Set 
{

private:
    List<Object>* list;

public:
    Set() 
    {
        list = new List<Object>;
    }
    ~Set() 
    {
        delete list; 
    }

    void insert(Object x) {
        List<Object> temp;

        if (!contains(x)) {  // Check if the element is not already in the list
            int i = 0;

            // Find the correct position to insert x
            while (i < list->size() && list->find_kth(i) <= x) {
                temp.push_back(list->pop_front());
                i++;
            }

            list->push_back(x);

            // Push the remaining elements from temp back into the list
            while (!temp.empty()) 
            {
                list->push_back(temp.pop_front());
            }       
        }
    }



    void remove(Object x) {
        List<Object> temp; // Temporary list to hold elements to keep
        bool found = false;

        while (!list->empty()) {
            Object current = list->pop_front();
            if (current == x) {
                found = true;
            }
            else {
                temp.push_back(current); // Add elements to temp list except the target
            }
        }

        // Push elements back into the original list
        while (!temp.empty()) {
            list->push_back(temp.pop_front());
        }

        if (!found) {
            cout << "Element not found" << endl;
        }
    }

    bool contains(Object element) const 
    {
        for (int i = 0; i < list->size(); i++)
        {
            if (list->find_kth(i) == element)
                return true;
        }
        return false;
    }

    void print() 
    {
        for (int i = 0; i < list->size(); i++)
        {
            cout << list->find_kth(i) << " " << endl;
        }
    }
 };