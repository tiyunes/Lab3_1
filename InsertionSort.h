#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
Sequence<T>* InsertionSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    Sequence<T>* sortedSequence = (Sequence<T>*)new ArraySequence<T>(s->GetLength());
    for (int i = 0; i < s->GetLength(); i++)
    {
        sortedSequence->Set(i, s->Get(i));
    }
    T buff;
    int prevIndex;
    for (int j = 0; j < sortedSequence->GetLength(); j++)
    {
        buff = sortedSequence->Get(j);
        prevIndex = j - 1;
        while (prevIndex >= 0 && !(cmp(sortedSequence->Get(prevIndex), buff)))
        {
            sortedSequence->Set((prevIndex + 1), sortedSequence->Get(prevIndex));
            sortedSequence->Set(prevIndex, buff);
            prevIndex--;
        }
    }
    return sortedSequence;
}


#endif // INSERTIONSORT_H_INCLUDED
