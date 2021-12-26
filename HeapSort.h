#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include "binary_heap.h"
#include <functional>


int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

template<typename T>
void swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<typename T>
void minHeapify(Sequence<T>* s, int size, function<bool(T, T)> cmp, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && cmp(s->Get(l),s->Get(i)))
    {
        smallest = l;
    }
    if (r < size && cmp(s->Get(r),s->Get(smallest)))
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&s->GetP(i), &s->GetP(smallest));
        minHeapify(s, size, cmp, smallest);
    }
}

template<typename T>
void HeapSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    for (int i = s->GetLength() / 2 - 1; i >= 0; i--)
    {
        minHeapify(s, s->GetLength(), cmp, i);
    }

    for (int i = s->GetLength() - 1; i > 0; i--)
    {
        swap(s->GetP(0), s->GetP(i));
        minHeapify(s, i, cmp, 0);
    }

    s->Reverse();
}




#endif // HEAPSORT_H_INCLUDED
