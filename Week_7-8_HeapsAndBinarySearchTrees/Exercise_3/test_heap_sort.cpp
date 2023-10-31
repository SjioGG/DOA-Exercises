using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include "heap_sort.h"
#include <chrono> // Include the chrono library for timing

void checkSort(const vector<int>& a) {
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            cout << "Error at " << i << endl;
        }
    }
    cout << "Finished checksort" << endl;
}

/**
 * @brief This program tests the heapSort function on an array of size NUM_ITEMS.
 *        The array is initialized with values in increasing order.
 *        The function is called twice and the time taken for each run is printed.
 * 
 * @return int 
 */
int main() {
    const int NUM_ITEMS = 5000;

    vector<int> a(NUM_ITEMS);  // for initializing in decreasing order
    for (int i = 0; i < a.size(); ++i) {
        a[i] = NUM_ITEMS - i;  // 
    } 


    /* vector<int> a(NUM_ITEMS); // for initializing in increasing order
    for (int i = 0; i < a.size(); ++i) {
        a[i] = i;
    } */

    for (int runs = 0; runs < 2; ++runs) {

        auto start_time = chrono::high_resolution_clock::now(); // Record start time

        // No need to call permute(a) since the array is already in increasing order
        heapSort(a);
       //checkSort(a);

        auto end_time = chrono::high_resolution_clock::now(); // Record end time
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time); // Calculate duration in microseconds

        cout << "Time taken for run " << runs << " with N = " << NUM_ITEMS << ":" << endl << duration.count() << " microseconds" << endl;
    }

    return 0;
}
