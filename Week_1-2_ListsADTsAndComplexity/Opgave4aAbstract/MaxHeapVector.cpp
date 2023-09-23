#include "MaxHeapVector.h"
using namespace std;

MaxHeapVector::MaxHeapVector()
{
}

MaxHeapVector::~MaxHeapVector()
{
}


bool MaxHeapVector::isEmpty() const
{
	return v.empty();
}

int MaxHeapVector::size()
{
	return v.size();
}

void MaxHeapVector::insert(const int x)
{
	return v.push_back(x);
}

const int MaxHeapVector::findMax() const
{
	if (!isEmpty())
	{
		int max = *max_element(v.begin(), v.end());
		return max;

	}
	throw runtime_error("Heap is empty");
}

int MaxHeapVector::deleteMax()
{
	if (!isEmpty())
	{
		int max = findMax();
		v.erase(remove(v.begin(), v.end(), max), v.end());
		return max;
	}
	throw runtime_error("Heap is empty");
}