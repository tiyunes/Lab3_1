#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

//template<typename T>
//void Swap (Sequence<T>* s, int i, int j)
//{
//    T buff = s->Get(i);
//    s->Set(i, s->Get(j));
//    s->Set(j, buff);
//}

template<typename T>
void QuickSortRight(Sequence<T>* s, function<bool(T, T)> cmp, int left, int right)
{
    int i, j;
    T pivot, buff;
    i = left;
    j = right;
    pivot = s->Get(right);
    do
    {
        while ((cmp(s->Get(i), pivot)) && (i < right)) i++;
        while ((cmp(pivot, s->Get(j))) && (j > left)) j--;
        if (i <= j)
        {
            buff = s->Get(i);
            s->Set(i, s->Get(j));
            s->Set(j, buff);
            i++;
            j--;
        }
    }
    while (i <= j);

    if (left < j) QuickSortRight(s, cmp, left, j);
    if (i < right) QuickSortRight(s, cmp, i, right);
}

#endif // QUICKSORT_H_INCLUDED
