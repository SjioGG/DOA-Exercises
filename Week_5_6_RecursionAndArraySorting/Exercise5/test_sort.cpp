#include <iostream>
#include <vector>
#include "sort.h"
#include <time.h>

using namespace std;

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
    const int NUM_ITEMS = 1000;

    vector<int> a(NUM_ITEMS);
    for (int i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] + 'a'; // initializes the vector with consecutive ASCII codes
    }

    for (int theSeed = 0; theSeed < 10; ++theSeed) // repeats the test with different random seeds
    {
        srand(time(0) + theSeed); // seeds the random number generator with the current time plus the seed value

        permute(a);       // permutes the vector randomly
        insertionSort(a); // sorts the vector using insertion sort
        checkSort(a);     // checks if the vector is sorted correctly

        permute(a);
        insertionSort(begin(a), end(a)); // sorts the vector using the STL sort function
        checkSort(a);

        permute(a);
        selectionSort(a); // sorts the vector using selection sort
        checkSort(a);
    }

    return 0;
}