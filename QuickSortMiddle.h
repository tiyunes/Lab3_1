#ifndef QUICKSORTM_H_INCLUDED
#define QUICKSORTM_H_INCLUDED
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
void QuickSortMiddle(Sequence<T>* s, function<bool(T, T)> cmp, int left, int right)
{
    int i, j;
    T pivot, buff;
    i = left;
    j = right;
    pivot = s->Get((left + right)/2);
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

    if (left < j) QuickSortMiddle(s, cmp, left, j);
    if (i < right) QuickSortMiddle(s, cmp, i, right);
}


#endif // QUICKSORTM_H_INCLUDED
