#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <sort.h>

using namespace std;
using namespace std::chrono;

void checkSort(const vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            cout << "Error at " << i << endl;
        }
    }
    cout << "Finished checksort" << endl;
}

template <typename AnyType>
void permute(vector<AnyType> &a)
{
    for (int j = 1; j < a.size(); ++j)
    {
        swap(a[j], a[rand() % j]);
    }
}

int main()
{
    const int NUM_ITEMS = 5000000;

    vector<int> a(NUM_ITEMS);
    for (int i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] + 'a';
    }

    srand(time(0) + 1);

    permute(a);

    auto start = high_resolution_clock::now();
    // quickSort(a);
    sort(a.begin(), a.end());
    auto stop = high_resolution_clock::now();

    checkSort(a);
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Sorting took " << duration.count() << " milliseconds." << endl;
    return 0;
}
