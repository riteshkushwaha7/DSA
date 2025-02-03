int MinHeap::extractMin() 
{
    if (heap_size <= 0) return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int x = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return x;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k) 
{
    if (heap_size >= capacity) return;

    int index = heap_size;
    harr[index] = k;
    heap_size++;

    while (index != 0 && harr[parent(index)] > harr[index]) {
        swap(harr[index], harr[parent(index)]);
        index = parent(index);
    }
}
