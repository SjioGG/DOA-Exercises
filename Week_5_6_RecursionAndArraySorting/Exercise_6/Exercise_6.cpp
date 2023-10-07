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

void counting_sort(vector<int> &A) // sorts a vector using counting sort
{
    int max_element = A[0];
    for (int i = 1; i < A.size(); i++) // find the maximum element in the vector
    {
        if (A[i] > max_element)
        {
            max_element = A[i]; // update the maximum element if the current element is larger than the maximum element
        }
    }
    vector<int> counting(max_element + 1, 0); // create a vector of size max_element + 1 and initialize all elements to 0
    for (int i = 0; i < A.size(); i++)        // count the number of occurrences of each element
    {
        counting[A[i]]++;
    }
    for (int i = 1; i < counting.size(); i++)
    {
        counting[i] += counting[i - 1]; // update the number of occurrences of each element to the number of elements less than or equal to it
    }
    vector<int> result(A.size());
    for (int i = A.size() - 1; i >= 0; i--)
    {
        result[counting[A[i]] - 1] = A[i];
        counting[A[i]]--;
    }
    A = result;
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
        counting_sort(a);
        checkSort(a);
    }

    return 0;
}