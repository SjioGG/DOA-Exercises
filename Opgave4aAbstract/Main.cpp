#include "MaxHeapVector.h"
#include <iostream>
using namespace std;

int main()
{
	MaxHeap* m = new MaxHeapVector();

	m->insert(2);
	m->insert(3);
	m->insert(4);
	m->insert(-1);
	m->deleteMax();
	m->findMax();
	delete m;
}
