/**
 * Insert item x, allowing duplicates.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    // Move up
    int node = ++currentSize;
    Comparable copy = x;

    array[0] = std::move(copy);
    for (; x < array[node / 2]; node /= 2)
        array[node] = std::move(array[node / 2]);
    array[node] = std::move(array[0]);
}

/**
 * Find the smallest item in the priority queue.
 * Return the smallest item, or throw Underflow if empty.
 */
template <typename Comparable>
const Comparable &BinaryHeap<Comparable>::findMin() const
{
    if (isEmpty())
        throw underflow_error{};
    return array[1];
}

/**
 * Find the largest item in the priority queue.
 * Return the largest item, or throw Underflow if empty.
 */
template <typename Comparable>
const Comparable &BinaryHeap<Comparable>::findMax() const
{
    if (isEmpty())
        throw underflow_error{};
    int maxIndex = 1;
    for (int i = 2; i <= currentSize; ++i)
    {
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }
    return array[maxIndex];
}

/**
 * Remove the minimum item.
 * Throws UnderflowException if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if (isEmpty())
        throw underflow_error("heap is empty.");
    array[1] = std::move(array[currentSize--]);
    minHeapify(1);
}

/**
 * Remove the minimum item and place it in minItem.
 * Throws Underflow if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable &minItem)
{
    if (isEmpty())
        throw underflow_error("heap is empty.");
    minItem = std::move(array[1]);
    array[1] = std::move(array[currentSize--]);
    minHeapify(1);
}

/**
 * Remove the maximum item.
 * Throws UnderflowException if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax()
{
    if (isEmpty())
        throw underflow_error("heap is empty.");
    int maxIndex = 1;
    for (int i = 2; i <= currentSize; ++i)
    {
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }
    array[maxIndex] = std::move(array[currentSize--]);
    maxHeapify(maxIndex);
}

/**
 * Remove the maximum item and place it in maxItem.
 * Throws Underflow if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Comparable &maxItem)
{
    if (isEmpty())
        throw underflow_error("heap is empty.");
    int maxIndex = 1;
    for (int i = 2; i <= currentSize; ++i)
    {
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }
    maxItem = std::move(array[maxIndex]);
    array[maxIndex] = std::move(array[currentSize--]);
    maxHeapify(maxIndex);
}

/**
 * Internal method to percolate down in the heap.
 * node is the index at which the percolate begins.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::minHeapify(int node)
{
    int child;
    Comparable tmp = std::move(array[node]);

    for (; node * 2 <= currentSize; node = child)
    {
        child = node * 2;
        if (child != currentSize && array[child + 1] < array[child])
            ++child;
        if (array[child] < tmp)
            array[node] = std::move(array[child]);
        else
            break;
    }
    array[node] = std::move(tmp);
}

template <typename Comparable>
void BinaryHeap<Comparable>::maxHeapify(int node)
{
    int child;
    Comparable tmp = std::move(array[node]);

    for (; node * 2 <= currentSize; node = child) // percolate down
    {
        child = node * 2;
        if (child != currentSize && array[child + 1] > array[child])
            ++child;
        if (array[child] > tmp)
            array[node] = std::move(array[child]);
        else
            break;
    }
    array[node] = std::move(tmp);
}