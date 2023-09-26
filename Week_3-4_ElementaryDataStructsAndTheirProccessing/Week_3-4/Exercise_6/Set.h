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
        List<Object>* temp = new List<Object>; // Temporary list to hold elements to keep
        int i = 0;
        if (!contains(x)) { // Check if the element is not already in the set
            while (i < list->size() && list->find_kth(i) <= x) {
                temp->push_front(list->pop_front()); // pop the lowest elemetns of list and store them in temp
                i++;
            }

            list->push_front(x); // push element into where it belongs

            while (!temp->empty()) {
                list->push_front(temp->pop_back()); // push the highest to lowest element on to the Set
            }
            delete temp;
        }
        else if (list->empty())
        {
            list->push_front(x);
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