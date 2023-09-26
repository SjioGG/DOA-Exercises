#pragma once
#include <vector>
#include <utility>
using namespace std;

template <typename Key, typename Value> // Key and Value are template parameters

class Dictionary {
private:
    vector<pair<Key, Value>> data; // vector of pairs for storing the key-value pairs

public:
    void insert(const Key& key, const Value& value) // insert a new pair
    {
        data.push_back(make_pair(key, value)); // make_pair creates a pair object if it doesn't exist already
    }


    bool contains(const Key& key) const // check if the dictionary contains a key
    {
        for (const auto& pair : data) 
        {
            if (pair.first == key) // if the key is found, return true
            {
                return true;
            }
        }
        return false;
    }

    Key& operator[](const Value& value) // return a reference to the value associated with the key
    {
        for (auto& pair : data) // iterate through the vector
        {
            if (pair.second == value)
            {
                return pair.first; // if the key is found, return the reference to the value
            }
        }                              
        return data.back().first; // return the reference to the value

    }

    bool empty() const // check if the dictionary is empty
    {
        return data.empty();
    }

    size_t size() const { // return the number of key-value pairs in the dictionary
        return data.size();
    }

};
