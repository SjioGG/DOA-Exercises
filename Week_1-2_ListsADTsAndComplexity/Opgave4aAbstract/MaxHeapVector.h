#pragma once
#include "MaxHeap.h"
#include <iostream>
class MaxHeapVector : public MaxHeap
{
private:
	vector<int> v;
public:
	MaxHeapVector();
	virtual ~MaxHeapVector();
	virtual bool isEmpty() const;
	virtual int size();
	virtual void insert(const int x);
	virtual const int findMax() const;
	virtual int deleteMax();

};

