#pragma once
#include <vector>
#include <iostream>
using namespace std;

class MaxHeap
{
private:
	std::vector<int>* heap_;
public:
	MaxHeap();
	~MaxHeap();
	// is the heap empty?
	bool isEmpty() const;
	// number of elements in the heap
	int size() ;
	// add an element to the heap
	void insert(const int x) ;
	// find the maximum element in the heap
	const int findMax() const;
	// delete and return the maximum element of the heap
	int deleteMax();
};