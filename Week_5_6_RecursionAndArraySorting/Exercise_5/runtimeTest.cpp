#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "sort.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// checks if a vector is sorted in ascending order
void checkSort(const vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (a[i] >= a[i + 1])
        {
            cout << "Error at " << i << endl;
        }
    }
    cout << "Finished checksort" << endl;
}

// permutes the elements of a vector randomly
template <typename AnyType>
void permute(vector<AnyType> &a)
{
    for (int j = 1; j < a.size(); ++j)
    {
        swap(a[j], a[rand() % j]); // swaps the j-th element with a random element from 0 to j-1
    }
}

template <typename AnyType>
void selectionSort(vector<AnyType> &a) // sorts a vector using selection sort
{
    for (int i = 0; i < a.size(); ++i) // for each element in the vector
    {
        int min = i; // assume the current element is the smallest
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] < a[min]) // if the current element is smaller than the smallest element
            {
                min = j;
            }
        }
        swap(a[i], a[min]); // swap the smallest element with the current element
    }
}

int main()
{
    int N;
    printf("Input N:");
    scanf("%d", &N);

    // Create a vector and initialize it with data
    vector<int> a(N);
    for (int i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] + 'a'; // Initializes the vector with consecutive ASCII codes
    }
    srand(time(0) + 1); // seeds the random number generator with the current time plus the seed value
    permute(a);
    insertionSort(a);
    checkSort(a);
    //  Measure execution time
    auto start = high_resolution_clock::now();
    selectionSort(a);
    auto stop = high_resolution_clock::now();
    // Calculate and print the execution time
    auto duration = duration_cast<milliseconds>(stop - start);
    checkSort(a);
    cout << "Sorting took " << duration.count() << " milliseconds." << endl;

    return 0;
}