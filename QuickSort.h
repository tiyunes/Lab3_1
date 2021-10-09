#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
void Swap (Sequence<T>* s, int i, int j)
{
    T buff = s->Get(i);
    s->Set(i, s->Get(j));
    s->Set(j, buff);
}

template<typename T>
int Partition (Sequence<T>* s, function<bool(T, T)> cmp, int first, int last)
{
    T pivot = s->Get(last);
    int i = (first - 1);
    for (int j = first; j <= (last - 1); j++)
    {
        if(cmp(s->Get(j), pivot))
        {
            i++;
            Swap(s, i, j);
        }
    }
    Swap(s, (i + 1), last);
    return (i + 1);
}
template<typename T>
void QuickSortH (Sequence<T>* s, function<bool(T, T)> cmp, int first, int last)
{
    if (first < last)
    {
        int pi = Partition(s, cmp, first, last);
        QuickSortH(s, cmp, first, pi - 1);
        QuickSortH(s, cmp, pi + 1, last);
    }
}

template<typename T>
Sequence<T>* QuickSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    Sequence<T>* sortedSequence = (Sequence<T>*)new ArraySequence<T>(s->GetLength());
    for (int m = 0; m < s->GetLength(); m++)
    {
        sortedSequence->Set(m, s->Get(m));
    }
    int pi = Partition(sortedSequence, cmp, 0, (s->GetLength() - 1));
    QuickSortH(sortedSequence, cmp, 0, pi - 1);
    QuickSortH(sortedSequence, cmp, pi + 1, (s->GetLength() - 1));
    return sortedSequence;
}

#endif // QUICKSORT_H_INCLUDED
