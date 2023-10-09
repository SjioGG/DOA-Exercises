#include <iostream>
#include <vector>
#include "sort.h"
#include <time.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

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
	const int NUM_ITEMS = 500000;

	vector<int> a(NUM_ITEMS);
	for (int i = 1; i < a.size(); ++i)
	{
		a[i] = a[i - 1] + 'a';
	}

	srand(time(0) + 1);

	permute(a);
	auto start = high_resolution_clock::now();
	quickSort(a);
	auto stop = high_resolution_clock::now();
	checkSort(a);
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Sorting took " << duration.count() << " milliseconds." << endl;
	return 0;
}
