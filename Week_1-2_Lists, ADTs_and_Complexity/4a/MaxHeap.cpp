#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
	heap_ = new vector<int>();
}

MaxHeap::~MaxHeap()
{
	delete heap_;
}


bool MaxHeap::isEmpty() const
{
	return heap_->empty();
}

int MaxHeap::size()
{
	return heap_->size();
}


void MaxHeap::insert(const int x)
{
    heap_->push_back(x);

    // Reheapify the heap using iterators... FOLLOWING IS NOT REALLY NECCESARRY
    auto current = heap_->end() - 1;
    while (current > heap_->begin())
        {
        auto parent = heap_->begin() + (current - heap_->begin() - 1) / 2;
        if (*current > *parent) 
        {
            std::swap(*current, *parent);
            current = parent;
        }
        else {
            break;
        }
    }
}

const int MaxHeap::findMax() const
{
    if (!isEmpty()) {
        int max = *std::max_element(heap_->begin(), heap_->end());
        return max;
    }
    throw std::runtime_error("Heap is empty");
}

int MaxHeap::deleteMax()
{
    if (!isEmpty()) {
        int max = findMax();
        heap_->erase(std::remove(heap_->begin(), heap_->end(), max), heap_->end());
        // Reheapify the heap (if needed) can be implemented here.
        return max;
    }
    throw std::runtime_error("Heap is empty");
}
