#include <iostream>
#include <algorithm>

template <typename T>
bool recursive_search(const T *arr, int size, const T &x)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[size - 1] == x)
    {
        return true;
    }
    return recursive_search(arr, size - 1, x);
}

template <typename T>
void recursive_minmax(const T *arr, int size, T &min, T &max)
{
    if (size == 1)
    {
        min = max = arr[0];
        return;
    }
    recursive_minmax(arr, size - 1, min, max);
    min = std::min(min, arr[size - 1]);
    max = std::max(max, arr[size - 1]);
}

int main()
{
    int arr[] = {3, 5, 2, 8, 1, 9, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]); // divide the size of an array spot with the size of the array to get an actual int.

    // search for element 5
    if (recursive_search(arr, size, 5))
    {
        std::cout << "Element 5 found in the array.\n";
    }
    else
    {
        std::cout << "Element 5 not found in the array.\n";
    }

    // find min and max elements
    int min, max;
    recursive_minmax(arr, size, min, max);
    std::cout << "Minimum element: " << min << "\n";
    std::cout << "Maximum element: " << max << "\n";

    return 0;
}
