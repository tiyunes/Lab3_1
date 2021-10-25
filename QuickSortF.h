#ifndef QUICKSORTF_H_INCLUDED
#define QUICKSORTF_H_INCLUDED
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
void QuickSortFH(Sequence<T>* s, function<bool(T, T)> cmp, int left, int right)
{
    int i, j;
    T pivot, buff;
    i = left;
    j = right;
    pivot = s->Get(left);
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

    if (left < j) QuickSortMH(s, cmp, left, j);
    if (i < right) QuickSortMH(s, cmp, i, right);
}

template<typename T>
Sequence<T>* QuickSortF(Sequence<T>* s, function<bool(T, T)> cmp)
{
    int i, j, left, right;
    T pivot, buff;
    left = 0; right = (s->GetLength() - 1);
    i = left;
    j = right;
    pivot = s->Get(0);
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

    if (left < j) QuickSortMH(s, cmp, left, j);
    if (i < right) QuickSortMH(s, cmp, i, right);

    return s;
}


#endif // QUICKSORTF_H_INCLUDED
