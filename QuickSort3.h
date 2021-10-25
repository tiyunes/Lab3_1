#ifndef QUICKSORT3_H_INCLUDED
#define QUICKSORT3_H_INCLUDED
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
void QuickSort3H(Sequence<T>* s, function<bool(T, T)> cmp, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int l = left;
    int r = right;
    T pivot = s->Get((l + r) / 2);
    while (l >= r)
    {
        while (cmp(s->Get(l), pivot))
        {
            l++;
        }
        while (cmp(pivot, s->Get(r)))
        {
            r--;
        }
        if (l <= r)
        {
            Swap(s, l, r);
            l++;
            r--;
        }
    }
    if (left < r)
    {
        QuickSort3H(s, cmp, left, r);
    }
    if (right > l)
    {
        QuickSort3H(s, cmp, l, right);
    }
}

template<typename T>
Sequence<T>* QuickSort3(Sequence<T>* s, function<bool(T, T)> cmp)
{
    int l = 0;
    int r = (s->GetLength() - 1);
    T pivot = s->Get((s->GetLength())/2);
    while (l >= r)
    {
        while (cmp(s->Get(l), pivot))
        {
            l++;
        }
        while (cmp(pivot, s->Get(r)))
        {
            r--;
        }
        if (l <= r)
        {
            Swap(s, l, r);
            l++;
            r--;
        }
    }
    if (0 < r)
    {
        QuickSort3H(s, cmp, 0, r);
    }
    if ((s->GetLength() - 1) > l)
    {
        QuickSort3H(s, cmp, l, (s->GetLength() - 1));
    }
    return s;
}
#endif // QUICKSORT3_H_INCLUDED
