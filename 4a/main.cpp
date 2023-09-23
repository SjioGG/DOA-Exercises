#include "MaxHeap.h"
int main()
{
	MaxHeap heap;
	MaxHeap heap2; // could add = MaxHeap(), but seems to have been done automagically

	heap.insert(20);
	heap.insert(25);
	heap.deleteMax();
	heap.findMax();
	heap2.insert(69);
	heap2.insert(40);
	heap2.deleteMax();
	heap2.findMax();
} 